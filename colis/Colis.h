#pragma once
#include<string.h>
#include <iostream>
using namespace std;


enum class TypeColis{
    standard,fragile
};
class Colis
{
protected:
    float volum;
    float poids;       // en kg
    float longeur;    // en cm
    float largeur;
    float hauteur;
    TypeColis type;
    string IdColis;
    static int compteur; 
    int distance;

public:
    Colis();
    Colis(float pd,  float lo, float la, float h,TypeColis ty);
    float getvolum()const;
    float getpoids()const;
    TypeColis gettype()const;
    string getIdColis()const;

    void setvolum(float vl);
    void setpoids(float pd);
    void settype(TypeColis ty);
    void setIdColis(string Id);

    virtual void afficher() const = 0;

    bool operator==(const Colis& other)const;
    friend ostream& operator<<(ostream& os, const Colis& col);

    virtual ~Colis() = default;

};

