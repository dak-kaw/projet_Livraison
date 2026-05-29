#pragma once
#include<string>
#include <iostream>

enum class TypeColis{
    Standard,Fragile
};
class Colis
{
protected:
    float volume;
    float poids;       // en kg
    float longueur;    // en cm
    float largeur;
    float hauteur;
    TypeColis type;
    string IdColis;
    static int compteur; 

public:
    Colis();
    Colis(float pd,  float lo, float la, float h,TypeColis ty);
    float getVolume()const;
    float getPoids()const;
    TypeColis getType()const;
    string getId()const;

    void setVolume(float vl);
    void setPoids(float pd);
    void setType(TypeColis ty);
    void setId(string Id);

    virtual void afficher() const = 0;

    bool operator==(const Colis& other)const;
    friend ostream& operator<<(ostream& os, const Colis& col);

    virtual ~Colis() = default;

};

