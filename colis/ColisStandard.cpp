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
#include <iostream>
#include "ColisStandard.h"
using namespace std;

int main() {

    // Création d’un colis standard
    ColisStandard c1(8.0, 15, 25, 35);

    // Affichage
    c1.afficher();
    cout << endl;

    // Test des getters
    cout << "ID : " << c1.getIdColis() << endl;
    cout << "Poids : " << c1.getpoids() << " kg" << endl;
    cout << "Volume : " << c1.getvolum() << " cm3" << endl;

    // Vérifier le type
    if (c1.gettype() == TypeColis::standard) {
        cout << "Ce colis est standard" << endl;
    }

    // Création d’un deuxième colis
    ColisStandard c2(8.0, 15, 25, 35);

    cout << "\nComparaison :" << endl;

    if (c1 == c2) {
        cout << "Les colis sont identiques" << endl;
    } else {
        cout << "Les colis sont differents" << endl;
    }

    // Rendre les IDs identiques pour tester ==
    c2.setIdColis(c1.getIdColis());

    if (c1 == c2) {
        cout << "Maintenant ils sont identiques" << endl;
    }

    return 0;
}