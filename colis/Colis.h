#pragma once
<<<<<<< HEAD
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
=======
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
>>>>>>> dev
    float largeur;
    float hauteur;
    TypeColis type;
    string IdColis;
<<<<<<< HEAD
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
=======
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
>>>>>>> dev

    virtual void afficher() const = 0;

    bool operator==(const Colis& other)const;
<<<<<<< HEAD
    friend ostream& operator<<(ostream& os, const Colis& col);
=======
    friend std::ostream& operator<<(std::ostream& os, const Colis& col);
>>>>>>> dev

    virtual ~Colis() = default;

};
<<<<<<< HEAD

=======
>>>>>>> dev
