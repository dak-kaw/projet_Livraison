#include "ColisStandard.h"
#include <iostream>
using namespace std;

<<<<<<< HEAD
ColisStandard::ColisStandard() : Colis() {}

ColisStandard::ColisStandard(float pd, float lo, float la, float h)
    : Colis(pd, lo, la, h, TypeColis::standard) {}

void ColisStandard::afficher() const {
    cout << "=== Colis Standard ===" << endl;
    cout << *this;
}
=======
ColisStandard::ColisStandard()
    : Colis(), prioritaire(false) {}

ColisStandard::ColisStandard(float pd, float lo, float la, float h, boll prio)
    : Colis(pd, lo, la, h, TypeColis::Standard),
    prioritaire(prio)
{}

bool ColisStandard::isPrioritaire() const {
    return prioritaire;
}

void ColisStandard::afficher() const {
    cout << "=== Colis Standard 
        << (prioritaire ? " [PRIORITAIRE]" : "")
        << "===\n";
    cout << *this;
}
>>>>>>> dev
