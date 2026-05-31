#ifndef VELO_H
#define VELO_H

#include "Transporteur.h"

class Velo : public Transporteur {
private:
    double capaciteMax;
    double vitesse;
    double coutParKm;
    double coutParKg;

public:
    Velo();

    bool canDeliver(const Colis& c) const override;
    double computeCost(const Colis& c) const override;
    double computeDelay(const Colis& c) const override;
};

#endif
