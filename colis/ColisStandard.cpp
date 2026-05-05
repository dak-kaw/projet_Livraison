#include "ColisStandard.h"
#include <iostream>
using namespace std;

ColisStandard::ColisStandard() : Colis() {}

ColisStandard::ColisStandard(float pd, float lo, float la, float h)
    : Colis(pd, lo, la, h, TypeColis::standard) {}

void ColisStandard::afficher() const {
    cout << "Colis Standard " << endl;
    cout << *this;
}