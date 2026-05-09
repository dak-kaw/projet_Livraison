#include <iostream>
#include <vector>

#include "Colis.h"
#include "Velo.h"
#include "Camion.h"
#include "Drone.h"
#include "Avion.h"
#include "SystemeLivraison.h"

using namespace std;

int main() {

    vector<Transporteur*> ts;

    ts.push_back(new Camion());
    ts.push_back(new Drone());
    ts.push_back(new Velo());
    ts.push_back(new Avion());

    Colis c(4, 20, 8, 3, TypeColis::standard, 50, false);

    Transporteur* t = SystemeLivraison::choisirTransporteur(c, ts);

    if (t) {
        cout << "Transporteur: " << t->getName() << endl;
        cout << "Cout: " << t->computeCost(c) << endl;
        cout << "Delai: " << t->computeDelay(c) << endl;
    }

    for (auto t : ts) delete t;

    return 0;
}