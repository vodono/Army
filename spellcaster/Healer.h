//
// Created by denysvysochanskyi on 19.04.18.
//

#ifndef ARMY_HEALER_H
#define ARMY_HEALER_H

#include "SpellCaster.h"
#include "../magicAbility/HealerMagicAbility.h"

class Healer : public SpellCaster {
public:
    Healer(const char* title, int hitPoints, int damage, int mana);
    virtual ~Healer();
};


#endif //ARMY_HEALER_H
