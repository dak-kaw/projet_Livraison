#include "SystemeLivraison.h"

Transporteur* SystemeLivraison::choisirTransporteur(
    const Colis& colis,
    const vector<Transporteur*>& transporteurs) {

    for (auto t : transporteurs) {
        if (t->canDeliver(colis)) {
            return t;
        }
    }

    return nullptr;
}