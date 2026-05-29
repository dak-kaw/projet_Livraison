#include "Colis.h"

int Colis::compteur = 0;

// Constructeur par défaut
Colis::Colis()
    : volume(0) , poids(0), longueur(0), largeur(0), hauteur(0),
        type(TypeColis::Standard),
        IdColis("")
{}        

// Constructeur paramétré
Colis::Colis(float pd, float lo, float la, float h, TypeColis ty)
    : poids(pd), longueur(lo), largeur(la), haiteur(h),
    volume(lo * la *h),
    type(ty)
{
    IdColis = "PKG-" + std::to_string(++compteur);
}

// Getters
float Colis::getVolume()const{
    return volume;
}
float Colis::getPoids()const{
    return poids;
}
TypeColis Colis::getType()const {
    return type;
}
std::string Colis::getId()const {
    return IdColis;
}

// Setters
void Colis::setVolume(float vl){
    if (vl > 0) volume = vl;
}
void Colis::setpoids(float pd){
    if (pd > 0) poids = pd;
}
void Colis::setType(TypeColis ty){
    type = ty;
}
void Colis::setIdColis(string id) {
    IdColis = id;
}

bool Colis::operator==(const Colis& other)const{
        return IdColis == other.IdColis ;
}

std::ostream& operator<<(std::ostream& os, const Colis& col){
    os << "ID     : " << col.IdColis << "\n"
       << "Poids  : " << col.poids   << " kg\n"
       << "Volume : " << col.volume  << " cm³\n"
       << "Type   : "
       << (col.type == TypeColis::Standard ? "Standard" : "Fragile")
       << "\n";
    
    return os;
}


