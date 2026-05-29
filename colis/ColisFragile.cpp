#include "ColisFragile.h"
#include <iostream>
using namespace std;

<<<<<<< HEAD
ColisFragile::ColisFragile(float pd, float lo, float la, float h)
    : Colis(pd, lo, la, h, TypeColis::fragile) {}

void ColisFragile::afficher() const {
    cout << "Colis Fragile " << endl;
    cout << *this;
}

bool ColisFragile::estFragile() const {
    return true;
}
=======
ColisFragile::ColisFragile(float pd, float lo, float la, float h, int niveau)
    : Colis(pd, lo, la, h, TypeColis::Fragile),
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
>>>>>>> dev
