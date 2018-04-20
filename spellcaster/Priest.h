//
// Created by denysvysochanskyi on 19.04.18.
//

#ifndef ARMY_PRIEST_H
#define ARMY_PRIEST_H

#include "SpellCaster.h"
#include "../magicAbility/PriestMagicAbility.h"

class Priest : public SpellCaster {
public:
    Priest(const char* title, int hitPoints, int damage, int mana);
    virtual ~Priest();
};


#endif //ARMY_PRIEST_H
