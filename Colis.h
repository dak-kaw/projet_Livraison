#ifndef COLIS_H
#define COLIS_H

#include <iostream>
#include <string>
using namespace std;

enum class TypeColis { standard, fragile };

class Colis {
private:
    float volum;
    float poids;
    float longeur, largeur, hauteur;
    TypeColis type;
    string IdColis;
    int Distance;

    static int compteur;

public:
    Colis();
    Colis(float pd, float lo, float la, float h, TypeColis ty, int d, bool f);

    float getvolum() const;
    float getpoids() const;
    string getIdColis() const;
    TypeColis gettype() const;
    float getDistance() const;

    void setvolum(float vl);
    void setpoids(float pd);
    void settype(TypeColis ty);
    void setIdColis(string id);
    void setDistance(int d);

    virtual void afficher() const; // ✔ مهم

    bool operator==(const Colis& other) const;

    friend ostream& operator<<(ostream& os, const Colis& col);

    virtual ~Colis() = default;
};

#endif