#include "Camion.h"
#include "Colis.h"

Camion::Camion(): Transporteur("Camion"){
    capaciteMax= 2500;
    vitesse = 80;
    coutParKm = 3.8;
    coutParKg = 2.3;
}

bool Camion::canDeliver(const Colis& c) const {
    return c.getPoids() <= capaciteMax;
}

double Camion::computeCost(const Colis& c) const {
    return c.getDistance() * coutParKm +
           c.getPoids() * coutParKg;
}

double Camion::computeDelay(const Colis& c) const {
    return c.getDistance() / vitesse;
}