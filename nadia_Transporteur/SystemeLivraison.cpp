#include "SystemeLivraison.h"

Transporteur* SystemeLivraison::choisirTransporteur(
    const Colis& colis,
    const std::vector<Transporteur*>& transporteurs)
{
    Transporteur* meilleur = nullptr;
    double coutMin = -1;

    for (auto t : transporteurs) {
        if (!t->canDeliver(colis)) continue;

        double cout = t->computeCost(colis);
        if (coutMin < 0 || cout < coutMin) {
            coutMin  = cout;
            meilleur = t;
        }
    }
    return meilleur;  
}
