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
    int distance;
    static int compteur; 

public:
    Colis();
    Colis(float pd,  float lo, float la, float h,TypeColis ty, int d);

    float getVolume()  const;
    float getPoids()  const;
    TypeColis getType()  const;
    string getId()  const;
    int getDistence()  const;

    void setVolume(float vl);
    void setPoids(float pd);
    void setType(TypeColis ty);
    void setDistance(int d);

    virtual void afficher() const = 0;

    bool operator==(const Colis& other)const;
    friend std::ostream& operator<<(std::ostream& os, const Colis& col);

    virtual ~Colis() = default;

};
