#ifndef TRANSPORTEUR_H
#define TRANSPORTEUR_H

#include <string>
using namespace std;

class Colis;

class Transporteur {
protected:
    string nom;

public:
    Transporteur(string n);

    virtual bool canDeliver(const Colis& c) const = 0;
    virtual double computeCost(const Colis& c) const = 0;
    virtual double computeDelay(const Colis& c) const = 0;

    string getName() const;

    virtual ~Transporteur();
};

#endif