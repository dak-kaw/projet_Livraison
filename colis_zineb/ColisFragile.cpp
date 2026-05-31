#include "ColisFragile.h"
#include <iostream>
using namespace std;

ColisFragile::ColisFragile(float pd, float lo, float la, float h, int niveau)
    : Colis(pd, lo, la, h, TypeColis::Fragile, 0),
    niveauFragilite(niveau)
{}

int ColisFragile::getNiveau() const {
    return niveauFragilite;
}

void ColisFragile::afficher() const {
    cout << "=== Colis Fragile (niveau "
        << niveauFragilite << "/3) ===\n";
    cout << *this;
}
