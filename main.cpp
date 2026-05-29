#include <iostream>
#include <vector>
#include <memory> // pour unique_ptr
#include "ColisStandard.h"
#include "ColisFragile.h"
#include "Velo.h"
#include "Camion.h"
#include "Drone.h"
#include "Avion.h"
#include "SystemeLivraison.h"

using namespace std;

int main() {

    std::vector<std::unique_ptr<Transporteur>> ts;
    ts.push_back(std::make_unique<Camion>());
    ts.push_back(std::make_unique<Drone>());
    ts.push_back(std::make_unique<Velo>());
    ts.push_back(std::make_unique<Avion>());

    // Conversion en vector de raw pointers pour choisirTransporteur
    std::vector<Transporteur*> rawTs;
    for (const auto& t : ts) rawTs.push_back(t.get());

    ColisStandard c(9.0f, 20.0f, 8.0f, 3.0f, 50);

    Transporteur* t = SystemeLivraison::choisirTransporteur(c, rawTs);

    if (t) {
        cout << "Transporteur: " << t->getNom() << endl;
        cout << "Cout: " << t->computeCost(c) << endl;
        cout << "Delai: " << t->computeDelay(c) << endl;
    }else {
        cout << "Aucun transporteur disponible.\n";
    }    

    return 0;
}
