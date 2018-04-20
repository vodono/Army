//
// Created by denysvysochanskyi on 19.04.18.
//

#ifndef ARMY_WARLOCK_H
#define ARMY_WARLOCK_H

#include "SpellCaster.h"
#include "../magicAbility/WarlockMagicAbility.h"

class Warlock : public SpellCaster {
public:
    Warlock(const char* title, int hitPoints, int damage, int mana);
    virtual ~Warlock();
};


#endif //ARMY_WARLOCK_H
