#include "Transporteur.h"

Transporteur::Transporteur(string n) : nom(n) {}

string Transporteur::getName() const {
    return nom;
}

Transporteur::~Transporteur() {}