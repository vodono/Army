//
// Created by denysvysochanskyi on 27.03.18.
//

#ifndef ARMY_WEREWOLF_H
#define ARMY_WEREWOLF_H

#include "Unit.h"
#include "../ability/WerewolfAbility.h"

#define WOLF_RATE 1.2

class Werewolf : public Unit {
public:
    Werewolf(const char* title, int hitPoints, int damage);
    virtual ~Werewolf();
};


#endif //ARMY_WEREWOLF_H
