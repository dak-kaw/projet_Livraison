#include "Drone.h"
#include "Colis.h"

Drone::Drone(): Transporteur("Drone"){
    capaciteMax = 4;
    vitesse = 80;
    coutParKm = 5.0;
    coutParKg = 1.2;
}

bool Drone::canDeliver(const Colis& c) const {
    return c.getpoids() <= capaciteMax && c.gettype() != TypeColis::fragile;
}

double Drone::computeCost(const Colis& c) const {
    return c.getDistance() * coutParKm;
}

double Drone::computeDelay(const Colis& c) const {
    return c.getDistance() / vitesse;
}