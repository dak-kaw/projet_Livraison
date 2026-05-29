#ifndef CAMION_H
#define CAMION_H

#include "Transporteur.h"

class Camion : public Transporteur {
private:
    double capaciteMax;
    double vitesse;
    double coutParKm;
    double coutParKg;

public:
    Camion();

    bool canDeliver(const Colis& c) const override;
    double computeCost(const Colis& c) const override;
    double computeDelay(const Colis& c) const override;
};

#endif
