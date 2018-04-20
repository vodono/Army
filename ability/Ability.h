//
// Created by denysvysochanskyi on 22.03.18.
//

#ifndef ARMY_ABILITY_H
#define ARMY_ABILITY_H

#include "../unit/Unit.h"

#define COUNTER_ATTACK_RATE 2

class Unit;

class Ability {
protected:
    Unit* owner;

public:
    Ability(Unit* owner);
    virtual ~Ability();

    virtual void attack(Unit* enemy) = 0;
    virtual void counterAttack(Unit* enemy);
    virtual void turnEnemy(Unit *enemy);
    virtual void turnMyself();
};

#endif //ARMY_ABILITY_H
