#include <iostream>
#include <map>
#include "../include/EntrepriseLivraison.h"
#include "../include/Transporteur.h" 
#include "../include/Colis.h"

// On inclut les interfaces minimales nécessaires pour les appels polymorphiques
// (ces classes seront fournies par les autres étudiantes)
// Pour que ce fichier compile seul, on suppose que Transporteur a canDeliver(Colis*)

// ============================================================
// Constructeur
// ============================================================
EntrepriseLivraison::EntrepriseLivraison() : prochainId(1) {}

EntrepriseLivraison::~EntrepriseLivraison() {
    for (Livraison* l : livraisons) delete l;
}

// ============================================================
// ajouterTransporteur
// ============================================================
void EntrepriseLivraison::ajouterTransporteur(Transporteur* t) {
    transporteurs.push_back(t);
}

// ============================================================
// creerLivraison — attribution automatique du transporteur
// Aucun if/else sur les types : on utilise canDeliver() (polymorphisme)
// ============================================================
Livraison* EntrepriseLivraison::creerLivraison(Colis* colis, const std::string& date) {
    Transporteur* choisi = nullptr;
    double        coutMin = -1;

    // On parcourt les transporteurs et on prend le premier qui peut livrer ce colis
    for (Transporteur* t : transporteurs) {
        if (!t->canDeliver(*colis)) {   // méthode virtuelle → polymorphisme
          double cout = t->computeCost(*colis);
        if (coutMin < 0 || cout < coutMin) {
            coutMin = cout;
            choisi  = t;
        }   
    }

    if (choisi == nullptr) {
        std::cout << "⚠ Aucun transporteur disponible pour ce colis.\n";
        return nullptr;
    }

    // Création de la livraison et ajout à la liste
    Livraison* liv = new Livraison(prochainId++, colis, choisi, date);
    livraisons.push_back(liv);
    std::cout << "Livraison #" << liv->getId() << " créée.\n";
    return liv;
}

// ============================================================
// mettreAJourEtat — cherche par ID et change l'état
// ============================================================
bool EntrepriseLivraison::mettreAJourEtat(int idLivraison,
                                           EtatLivraison nouvelEtat,
                                           const std::string& date) {
    Livraison* l = chercherParId(idLivraison);
    if (l == nullptr) {
        std::cout << "⚠ Livraison #" << idLivraison << " introuvable.\n";
        return false;
    }
    l->setEtat(nouvelEtat, date);
    return true;
}

// ============================================================
// chercherParId — retourne un pointeur ou nullptr
// ============================================================
Livraison* EntrepriseLivraison::chercherParId(int id) {
    for (Livraison* l : livraisons)
        if (l->getId() == id) return l;
    return nullptr;
}

// ============================================================
// afficherToutes — liste toutes les livraisons
// ============================================================
void EntrepriseLivraison::afficherToutes() const {
    if (livraisons.empty()) {
        std::cout << "Aucune livraison enregistrée.\n";
        return;
    }
    std::cout << "\n=== Liste des livraisons (" << livraisons.size() << ") ===\n";
    for (const Livraison* l : livraisons) {
        std::cout << l << "\n";   // utilise operator<<
    }
}

// ============================================================
// genererRapport — statistiques et détail de chaque livraison
// ============================================================
void EntrepriseLivraison::genererRapport() const {
    // Comptage par état avec une map
    std::map<EtatLivraison, int> compteur;
    compteur[EtatLivraison::EnAttente] = 0;
    compteur[EtatLivraison::EnTransit] = 0;
    compteur[EtatLivraison::Livre]     = 0;

    for (const auto& l : livraisons) {
        compteur[l.getEtat()]++;
    }

    std::cout << "\n╔══════════════════════════════════════╗\n";
    std::cout << "║        RAPPORT DE LIVRAISONS         ║\n";
    std::cout << "╠══════════════════════════════════════╣\n";
    std::cout << "║  Total       : " << livraisons.size() << "\n";
    std::cout << "║  En attente  : " << compteur[EtatLivraison::EnAttente] << "\n";
    std::cout << "║  En transit  : " << compteur[EtatLivraison::EnTransit] << "\n";
    std::cout << "║  Livrés      : " << compteur[EtatLivraison::Livre]     << "\n";
    std::cout << "╚══════════════════════════════════════╝\n";

    // Détail complet avec historique
    std::cout << "\n--- Détail des livraisons ---\n";
    for (const auto& l : livraisons) {
        l.afficher();
    }
}
