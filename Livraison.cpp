#include "Livraison.h"

Livraison::Livraison(Colis* c, Transporteur* t)
    : colis(c), transporteur(t), etat(EtatLivraison::EN_ATTENTE) {
    historique.push_back("Creation EN_ATTENTE");
}

void Livraison::changerEtat(EtatLivraison e) {
    etat = e;
    historique.push_back("Etat modifie");
}

string Livraison::getEtatString() const {
    switch (etat) {
        case EtatLivraison::EN_ATTENTE: return "EN_ATTENTE";
        case EtatLivraison::EN_TRANSIT: return "EN_TRANSIT";
        case EtatLivraison::LIVRE: return "LIVRE";
    }
    return "";
}

void Livraison::afficher() const {
    cout << "Colis: " << colis->getType() << endl;
    cout << "Transporteur: " << transporteur->getNom() << endl;
    cout << "Etat: " << getEtatString() << endl;
}

void Livraison::afficherHistorique() const {
    for (auto& h : historique)
        cout << "- " << h << endl;
}