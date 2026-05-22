#pragma once
#include "Colis.h"

class ColisFragile : public Colis
{
public:
    ColisFragile(float pd, float lo, float la, float h);

    void afficher() const override;

    bool estFragile() const;
};