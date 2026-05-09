#include "Camion.h"
#include "Colis.h"

Camion::Camion(): Transporteur("Camion"){
    capaciteMax= 2500;
    vitesse = 80;
    coutParKm = 3.2;
    coutParKg = 2.5;
}

bool Camion::canDeliver(const Colis& c) const {
    return c.getpoids() <= capaciteMax;
}

double Camion::computeCost(const Colis& c) const {
    return c.getDistance() * coutParKm +
           c.getpoids() * coutParKg;
}

double Camion::computeDelay(const Colis& c) const {
    return c.getDistance() / vitesse;
}