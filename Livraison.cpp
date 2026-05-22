#include <iostream>
#include "../include/Livraison.h"

// ============================================================
// Constructeur
// ============================================================
Livraison::Livraison(int id, Colis* colis, Transporteur* transporteur, const std::string& date)
    : id(id), colis(colis), transporteur(transporteur),
      etat(EtatLivraison::EnAttente), dateCreation(date)
{
    // On enregistre l'état initial dans l'historique
    historiqueEtats.push_back("[" + date + "] Livraison créée — état : En attente");
}

// ============================================================
// Getters
// ============================================================
int           Livraison::getId()           const { return id; }
Colis*        Livraison::getColis()        const { return colis; }
Transporteur* Livraison::getTransporteur() const { return transporteur; }
EtatLivraison Livraison::getEtat()         const { return etat; }
std::string   Livraison::getDateCreation() const { return dateCreation; }

const std::vector<std::string>& Livraison::getHistorique() const {
    return historiqueEtats;
}

// ============================================================
// setEtat — met à jour l'état et enregistre la transition
// ============================================================
void Livraison::setEtat(EtatLivraison nouvelEtat, const std::string& date) {
    std::string ancienEtat = etatToString(etat);
    etat = nouvelEtat;
    std::string nouvelEtatStr = etatToString(nouvelEtat);

    // Enregistrement de la transition dans l'historique
    std::string entree = "[" + date + "] " + ancienEtat + " → " + nouvelEtatStr;
    historiqueEtats.push_back(entree);

    std::cout << "  ✔ Livraison #" << id << " : " << ancienEtat
              << " → " << nouvelEtatStr << "\n";
}

// ============================================================
// afficher — résumé de la livraison
// ============================================================
void Livraison::afficher() const {
    std::cout << "┌─ Livraison #" << id << " ─────────────────────\n";
    std::cout << "│  État       : " << etatToString(etat) << "\n";
    std::cout << "│  Créée le   : " << dateCreation << "\n";
    std::cout << "│  Historique :\n";
    for (const auto& ligne : historiqueEtats) {
        std::cout << "│    " << ligne << "\n";
    }
    std::cout << "└──────────────────────────────────────\n";
}

// ============================================================
// Surcharge de l'opérateur <<
// ============================================================
std::ostream& operator<<(std::ostream& os, const Livraison& l) {
    os << "Livraison #" << l.id
       << " | État : " << etatToString(l.etat)
       << " | Créée : " << l.dateCreation;
    return os;
}