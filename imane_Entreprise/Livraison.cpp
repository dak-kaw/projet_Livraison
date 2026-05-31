#include <iostream>
#include "Livraison.h"
#include "../nadia_Transporteur/Transporteur.h"
#include "../colis_zineb/Colis.h"
#include <stdexcept>

// ============================================================
// Constructeur
// ============================================================
Livraison::Livraison(int id, Colis* colis, Transporteur* transporteur, const std::string& date)
    : id(id), colis(colis), transporteur(transporteur),
    etat(EtatLivraison::EnAttente), dateCreation(date),
    coutTotal (transporteur->computeCost (*colis)),
    delaiJours(transporteur->computeDelay(*colis))

{
    // On enregistre l'etat initial dans l'historique
    historiqueEtats.push_back("[" + date + "] Livraison creee - etat : En attente");
}

// ============================================================
// Getters
// ============================================================
int           Livraison::getId()           const { return id; }
Colis*        Livraison::getColis()        const { return colis; }
Transporteur* Livraison::getTransporteur() const { return transporteur; }
EtatLivraison Livraison::getEtat()         const { return etat; }
std::string   Livraison::getDateCreation() const { return dateCreation; }
float Livraison::getCout()  const { return coutTotal;  }
int   Livraison::getDelai() const { return delaiJours; }

const std::vector<std::string>& Livraison::getHistorique() const {
    return historiqueEtats;
}

// ============================================================
// setEtat - met a jour l'etat et enregistre la transition
// ============================================================
void Livraison::setEtat(EtatLivraison nouvelEtat, const std::string& date) {
    
    if (static_cast<int>(nouvelEtat) <= static_cast<int>(etat)) {
        throw std::logic_error(
            "Transition invalide : impossible de reculer l'etat");
    }
    std::string ancienEtat = etatToString(etat);
    etat = nouvelEtat;
    std::string nouvelEtatStr = etatToString(nouvelEtat);

    // Enregistrement de la transition dans l'historique
    std::string entree = "[" + date + "] " + ancienEtat + " -> " + nouvelEtatStr;
    historiqueEtats.push_back(entree);

    std::cout << "  Livraison #" << id << " : " << ancienEtat
              << " -> " << nouvelEtatStr << "\n";
}

// ============================================================
// afficher - resume de la livraison
// ============================================================
void Livraison::afficher() const {
    std::cout << "Livraison #" << id << "\n";
    std::cout << "  Etat       : " << etatToString(etat) << "\n";
    std::cout << "  Creee le   : " << dateCreation << "\n";
    std::cout << "  Historique :\n";
    for (const auto& ligne : historiqueEtats) {
        std::cout << "    " << ligne << "\n";
    }
    std::cout << "--------------------------------------\n";
}

// ============================================================
// Surcharge de l'opérateur <<
// ============================================================
std::ostream& operator<<(std::ostream& os, const Livraison& l) {
    os << "Livraison #" << l.id
       << " | Etat : " << etatToString(l.etat)
       << " | Creee : " << l.dateCreation;
    return os;
}
