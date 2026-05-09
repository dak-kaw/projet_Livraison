#include "Velo.h"
#include "Colis.h"

Velo::Velo(): Transporteur("Velo"){
    capaciteMax = 15;
    vitesse = 20;
    coutParKm = 1.2;
    coutParKg = 1.5;
}
       

bool Velo::canDeliver(const Colis& c) const {
    return c.getpoids() <= capaciteMax;
}

double Velo::computeCost(const Colis& c) const {
    return c.getDistance() * coutParKm +
           c.getpoids() * coutParKg;
}

double Velo::computeDelay(const Colis& c) const {
    return c.getDistance() / vitesse;
}