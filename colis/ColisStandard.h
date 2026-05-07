#pragma once
#include "Colis.h"

class ColisStandard : public Colis {
public:
    ColisStandard();
    ColisStandard(float pd, float lo, float la, float h);

    void afficher() const override;
};