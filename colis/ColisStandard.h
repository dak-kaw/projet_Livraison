#pragma once
#include "Colis.h"

class ColisStandard : public Colis {
<<<<<<< HEAD
public:
    ColisStandard();
    ColisStandard(float pd, float lo, float la, float h);

    void afficher() const override;
};
=======
private:
    bool prioritaire;
public:
    ColisStandard();
    ColisStandard(float pd, float lo, float la, float h, bool prio = false);

    void afficher() const override;
    bool isPrioritaire() const;
};
>>>>>>> dev
