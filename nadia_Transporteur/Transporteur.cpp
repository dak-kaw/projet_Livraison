#include "Transporteur.h"

#include <iostream>

Transporteur::Transporteur(std::string n) : nom(n) {}

std::string Transporteur::getNom() const {
    return nom;
}

Transporteur::~Transporteur() {}

void Transporteur::afficher() const {
    std::cout << "Transporteur: " << nom << std::endl;
}