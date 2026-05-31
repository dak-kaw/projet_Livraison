#pragma once
#include "Colis.h"

class ColisFragile : public Colis
{
private: 
    int niveauFragilite;

public:
    ColisFragile(float pd, float lo, float la, float h, int niveau = 1);

    void afficher() const override;
    int getNiveau() const;
};
