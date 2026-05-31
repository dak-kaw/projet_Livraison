#include "Avion.h"
#include "Colis.h"

Avion::Avion(): Transporteur("Avion"){
    vitesse = 750;
    coutParKm = 5.6;
    coutParTonne = 200.0;
    capaciteMax = 100000.0;
}

bool Avion::canDeliver(const Colis& c) const {
    return c.getPoids() <= capaciteMax;
}

double Avion::computeCost(const Colis& c) const {
    return c.getDistance() * coutParKm;
}

double Avion::computeDelay(const Colis& c) const {
    return c.getDistance() / vitesse;
}