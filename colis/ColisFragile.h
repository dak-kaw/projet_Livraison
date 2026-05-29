#pragma once
#include "Colis.h"

class ColisFragile : public Colis
{
<<<<<<< HEAD
public:
    ColisFragile(float pd, float lo, float la, float h);

    void afficher() const override;

    bool estFragile() const;
};
=======
private: 
    int niveauFragilite;

public:
    ColisFragile(float pd, float lo, float la, float h, int niveau = 1);

    void afficher() const override;
    int getNiveau() const;
};
>>>>>>> dev
