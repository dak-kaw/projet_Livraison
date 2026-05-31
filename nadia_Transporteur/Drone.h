#ifndef DRONE_H
#define DRONE_H

#include "Transporteur.h"

class Drone : public Transporteur {
private:
    double capaciteMax;
    double vitesse;
    double coutParKm;
    double coutParKg;

public:
    Drone();

    bool canDeliver(const Colis& c) const override;
    double computeCost(const Colis& c) const override;
    double computeDelay(const Colis& c) const override;
};

#endif