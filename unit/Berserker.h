//
// Created by denysvysochanskyi on 27.03.18.
//

#ifndef ARMY_BERSERKER_H
#define ARMY_BERSERKER_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Berserker : public Unit {
public:
    Berserker(const char* title, int hitPoints, int damage);
    virtual ~Berserker();

    int takeMagicDamage(int dmg);
};


#endif //ARMY_BERSERKER_H
