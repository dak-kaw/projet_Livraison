#ifndef SYSTEMELIVRAISON_H
#define SYSTEMELIVRAISON_H

#include <vector>
#include "Transporteur.h"
#include "Colis.h"

using namespace std;

class SystemeLivraison {
public:
    static Transporteur* choisirTransporteur(
        const Colis& colis,
        const vector<Transporteur*>& transporteurs
    );
};

#endif
