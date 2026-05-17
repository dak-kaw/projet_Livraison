#include "Livraison.h"

Livraison::Livraison(Colis* c, Transporteur* t) 
    : colis(c), transporteur(t), etat(EtatLivraison::EN_ATTENTE) {
    ajouterEvenement("Initialisation de la livraison.");
}

void Livraison::mettreAJourEtat(EtatLivraison nouvelEtat) {
    this->etat = nouvelEtat;
    ajouterEvenement("Changement d'état vers : " + getEtatString());
}

void Livraison::ajouterEvenement(const std::string& message) {
    historique.push_back(message); // Utilisation de la STL vector
}

std::string Livraison::getEtatString() const {
    switch (etat) {
        case EtatLivraison::EN_ATTENTE: return "En attente";
        case EtatLivraison::EN_TRANSIT: return "En transit";
        case EtatLivraison::LIVRE:      return "Livré";
        default:                        return "Inconnu";
    }
}

void Livraison::afficherHistorique() const {
    std::cout << "Historique de la livraison :" << std::endl;
    for (const auto& event : historique) {
        std::cout << "- " << event << std::endl;
    }
}