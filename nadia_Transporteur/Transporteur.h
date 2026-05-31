#ifndef TRANSPORTEUR_H
#define TRANSPORTEUR_H

#include <string>

class Colis;

class Transporteur {
protected:
    std::string nom;

public:
    Transporteur(std::string n);

    virtual bool canDeliver(const Colis& c) const = 0;
    virtual double computeCost(const Colis& c) const = 0;
    virtual double computeDelay(const Colis& c) const = 0;

    std::string getNom() const;
    virtual void afficher() const;

    virtual ~Transporteur();
};

#endif
