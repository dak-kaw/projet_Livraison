#include "Colis.h"
int Colis::compteur = 0;
Colis::Colis(){
    volum = 0;
    poids = 0;
    longeur = largeur = hauteur = 0;
    type = TypeColis::standard;
    IdColis = "";
}
Colis::Colis(float pd, float lo, float la, float h, TypeColis ty){
    longeur = lo;
    largeur = la;
    hauteur = h;
    poids = pd;
    type = ty;

    volum = longeur * largeur * hauteur;

    this->IdColis = "PKG-" + std::to_string(++compteur);
}
float Colis::getvolum()const{
    return volum;
}
string Colis::getIdColis()const{
    return IdColis;
}
float Colis::getpoids()const{
    return poids;
}
TypeColis Colis::gettype()const {
    return type;
}
void Colis::setvolum(float vl){
    volum = vl;
}
void Colis::setpoids(float pd){
    poids = pd;
}
void Colis::settype(TypeColis ty){
    type = ty;
}
void Colis::setIdColis(string id) {
    IdColis = id;
}
bool Colis::operator==(const Colis& other)const{
        return IdColis == other.IdColis ;
}
std::ostream& operator<<(ostream& os, const Colis& col){
    
    os << "Poids " << col.poids << endl;
    os << "Volume " << col.volum << endl;
    os << "ID: " << col.IdColis << endl;
    if (col.type == TypeColis::standard)
        os << "Type: Standard" << endl;
    else
        os << "Type: Fragile" << endl;

    return os;
}


