#include "ColisStandard.h"
#include <iostream>
using namespace std;

ColisStandard::ColisStandard()
    : Colis(), prioritaire(false) {}

ColisStandard::ColisStandard(float pd, float lo, float la, float h, bool prio)
    : Colis(pd, lo, la, h, TypeColis::Standard, 0),
      prioritaire(prio)
{}

bool ColisStandard::isPrioritaire() const {
    return prioritaire;
}

void ColisStandard::afficher() const {
    cout << "=== Colis Standard"
        << (prioritaire ? " [PRIORITAIRE]" : "")
        << "===\n";
    cout << *this;
}
