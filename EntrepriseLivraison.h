#pragma once
#include "Livraison.h"
#include <vector>
using namespace std;

class EntrepriseLivraison {
private:
    vector<Livraison*> livraisons;

public:
    void ajouterLivraison(Livraison* l);
    void afficherToutes() const;
    void afficherHistoriques() const;
};