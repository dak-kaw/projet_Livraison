#include "EntrepriseLivraison.h"
#include <iostream>

void EntrepriseLivraison::ajouterLivraison(Livraison* l) {
    livraisons.push_back(l);
}

void EntrepriseLivraison::afficherToutes() const {
    for (auto l : livraisons) {
        cout << "------\n";
        l->afficher();
    }
}

void EntrepriseLivraison::afficherHistoriques() const {
    for (auto l : livraisons) {
        cout << "======\n";
        l->afficherHistorique();
    }
}