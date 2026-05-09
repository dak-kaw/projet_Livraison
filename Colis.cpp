#include "Colis.h"

int Colis::compteur = 0;

Colis::Colis() {
    volum = poids = longeur = largeur = hauteur = 0;
    type = TypeColis::standard;
    IdColis = "";
    Distance = 0;
}

Colis::Colis(float pd, float lo, float la, float h, TypeColis ty, int d, bool f) {
    poids = pd;
    longeur = lo;
    largeur = la;
    hauteur = h;
    type = f ? TypeColis::fragile : ty;
    Distance = d;

    volum = longeur * largeur * hauteur;
    IdColis = "PKG-" + to_string(++compteur);
}

float Colis::getvolum() const { return volum; }
float Colis::getpoids() const { return poids; }
string Colis::getIdColis() const { return IdColis; }
TypeColis Colis::gettype() const { return type; }
float Colis::getDistance() const { return Distance; }

void Colis::setvolum(float vl) { volum = vl; }
void Colis::setpoids(float pd) { poids = pd; }
void Colis::settype(TypeColis ty) { type = ty; }
void Colis::setIdColis(string id) { IdColis = id; }
void Colis::setDistance(int d) { Distance = d; }

void Colis::afficher() const {
    cout << *this;
}

bool Colis::operator==(const Colis& other) const {
    return IdColis == other.IdColis;
}

ostream& operator<<(ostream& os, const Colis& col) {
    os << "ID: " << col.IdColis << endl;
    os << "Poids: " << col.poids << endl;
    os << "Volume: " << col.volum << endl;
    os << "Distance: " << col.Distance << endl;
    os << "Type: " << (col.type == TypeColis::fragile ? "Fragile" : "Standard") << endl;
    return os;
}