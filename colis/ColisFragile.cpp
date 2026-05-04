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
#include <iostream>
#include "ColisFragile.h"
using namespace std;

int main() {

    // Création d’un colis fragile
    ColisFragile c1(5.5, 10, 20, 30);

    // Affichage
    c1.afficher();
    cout << endl;

    // Tester les getters
    cout << "ID : " << c1.getIdColis() << endl;
    cout << "Poids : " << c1.getpoids() << " kg" << endl;
    cout << "Volume : " << c1.getvolum() << " cm3" << endl;

    // Tester estFragile()
    if (c1.estFragile()) {
        cout << "Ce colis est fragile" << endl;
    }

    // Création d’un deuxième colis
    ColisFragile c2(5.5, 10, 20, 30);

    cout << "\nComparaison :" << endl;

    if (c1 == c2) {
        cout << "Les colis sont identiques" << endl;
    } else {
        cout << "Les colis sont differents" << endl;
    }

    // Forcer même ID pour tester ==
    c2.setIdColis(c1.getIdColis());

    if (c1 == c2) {
        cout << "Maintenant ils sont identiques" << endl;
    }

    return 0;
}