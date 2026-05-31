#ifndef AVION_H
#define AVION_H

#include "Transporteur.h"

class Avion : public Transporteur {
private:
    double vitesse;
    double coutParKm;
    double coutParTonne;
    double capaciteMax;

public:
    Avion();

    bool canDeliver(const Colis& c) const override;
    double computeCost(const Colis& c) const override;
    double computeDelay(const Colis& c) const override;
};

#endif