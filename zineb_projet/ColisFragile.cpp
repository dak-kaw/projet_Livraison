#include "ColisFragile.h"
#include <iostream>
using namespace std;

ColisFragile::ColisFragile(float pd, float lo, float la, float h)
    : Colis(pd, lo, la, h, TypeColis::fragile) {}

void ColisFragile::afficher() const {
    cout << "Colis Fragile " << endl;
    cout << *this;
}

bool ColisFragile::estFragile() const {
    return true;
}