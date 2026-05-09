#pragma once
#include "../colis/Colis.h"
#include "../transporteurs/Transporteur.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

enum class EtatLivraison {
    EN_ATTENTE,
    EN_TRANSIT,
    LIVRE
};

class Livraison {
private:
    Colis* colis;
    Transporteur* transporteur;
    EtatLivraison etat;
    vector<string> historique;

public:
    Livraison(Colis* c, Transporteur* t);

    void changerEtat(EtatLivraison e);
    void afficher() const;
    void afficherHistorique() const;
    string getEtatString() const;
};