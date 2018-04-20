//
// Created by denysvysochanskyi on 27.03.18.
//

#ifndef ARMY_ROGUE_H
#define ARMY_ROGUE_H

#include "Unit.h"
#include "../ability/RogueAbility.h"

class Rogue : public Unit {
public:
    Rogue(const char* title, int hitPoints, int damage);
    virtual ~Rogue();
};

#endif //ARMY_ROGUE_H
