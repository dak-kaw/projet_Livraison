#include "Rapport.h"
#include <iostream>
#include <numeric>    // std::accumulate
#include <iomanip>    // std::fixed, std::setprecision
#include <algorithm>  // std::count_if
#include "../nadia_Transporteur/Transporteur.h"
#include "../imane_Entreprise/Livraison.h"
 

Rapport::Rapport(const std::vector<Livraison*>& livs, std::string date)
    : livraisons(livs), dateGeneration(date) {}
 
// Compte les livraisons dans un etat donne
int Rapport::compterParEtat(EtatLivraison e) const {
    return std::count_if(
        livraisons.begin(), livraisons.end(),
        [e](const Livraison* l) { return l->getEtat() == e; }
    );
}

// Somme tous les couts avec std::accumulate
float Rapport::calculerCoutTotal() const {
    return std::accumulate(
        livraisons.begin(), livraisons.end(), 0.0f,
        [](float somme, const Livraison* l) {
            return somme + l->getCout();
        }
    );
}

// Delai moyen : somme des delais / nombre de livraisons
float Rapport::calculerDelaiMoyen() const {
    if (livraisons.empty()) return 0.0f;
    float total = std::accumulate(
        livraisons.begin(), livraisons.end(), 0.0f,
        [](float s, const Livraison* l) { return s + l->getDelai(); }
    );
    return total / livraisons.size();
}

float Rapport::calculerCoutMoyen() const {
    if (livraisons.empty()) return 0.0f;
    return calculerCoutTotal() / livraisons.size();
}

void Rapport::afficherResume() const {
    int total    = livraisons.size();
    int attente  = compterParEtat(EtatLivraison::EnAttente);
    int transit  = compterParEtat(EtatLivraison::EnTransit);
    int livrees  = compterParEtat(EtatLivraison::Livre);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "== RAPPORT DU " << dateGeneration << " ==\n"
            << "  Total livraisons : " << total   << "\n"
            << "  En attente       : " << attente << "\n"
            << "  En transit       : " << transit << "\n"
            << "  Livrees         : " << livrees << "\n"
            << "  Cout total      : " << calculerCoutTotal()  << " DH\n"
            << "  Cout moyen      : " << calculerCoutMoyen()  << " DH\n"
            << "  Delai moyen     : " << calculerDelaiMoyen() << " j\n";
}

void Rapport::afficherDetail() const {
        std::cout << "== DETAIL DES LIVRAISONS ==\n";
    for (const auto& l : livraisons) {
        l->afficher();
        std::cout << "  ________________\n";
    }
}

void Rapport::afficherHistorique() const {
    std::cout << "== HISTORIQUE COMPLET ==\n";
    for (const auto& l : livraisons) {
        std::cout << "  Livraison " << l->getId() << ":\n";
        for (const auto& ligne : l->getHistorique())
            std::cout << "    " << ligne << "\n";
    }
}

void Rapport::exporterFichier(const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);

    if (!fichier.is_open()) {
        std::cerr << "Erreur: impossible d'ouvrir " << nomFichier << "\n";
        return;
    }

    fichier << std::fixed << std::setprecision(2);
    fichier << "==============================\n"
            << " RAPPORT DE LIVRAISON - " << dateGeneration << "\n"
            << "==============================\n\n";
    
        // Resume statistique
        fichier << "RESUME\n"
            << "  Total        : " << livraisons.size()       << "\n"
            << "  Livrees      : " << compterParEtat(EtatLivraison::Livre) << "\n"
            << "  En transit   : " << compterParEtat(EtatLivraison::EnTransit) << "\n"
            << "  En attente   : " << compterParEtat(EtatLivraison::EnAttente) << "\n"
            << "  Cout total   : " << calculerCoutTotal()  << " DH\n"
            << "  Cout moyen   : " << calculerCoutMoyen()  << " DH\n"
            << "  Delai moyen  : " << calculerDelaiMoyen() << " j\n\n";

        // Detail de chaque livraison + historique
        fichier << "DETAIL\n";
    for (const Livraison* l : livraisons) {
        fichier << "  [" << l->getId() << "] "
                << etatToString(l->getEtat()) << "\n"
                << "  Transporteur : " << l->getTransporteur()->getNom() << "\n"
                << "  Cout         : " << l->getCout()  << " DH\n"
                << "  Delai        : " << l->getDelai() << " j\n";
        for (const auto& h : l->getHistorique())
            fichier << "    " << h << "\n";
        fichier << "\n";
    }        
    fichier.close(); // fermeture explicite (bonne pratique)
    std::cout << "Rapport exporte : " << nomFichier << "\n";
}