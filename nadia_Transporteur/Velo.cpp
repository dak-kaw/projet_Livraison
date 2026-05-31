#include "Velo.h"
#include "Colis.h"

Velo::Velo(): Transporteur("Velo"){
    capaciteMax = 15;
    vitesse = 20;
    coutParKm = 1.12;
    coutParKg = 1.5;
}
       

bool Velo::canDeliver(const Colis& c) const {
    return c.getPoids() <= capaciteMax;
}

double Velo::computeCost(const Colis& c) const {
    return c.getDistance() * coutParKm +
           c.getPoids() * coutParKg;
}

double Velo::computeDelay(const Colis& c) const {
    return c.getDistance() / vitesse;
}