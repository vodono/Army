//
// Created by denysvysochanskyi on 27.03.18.
//

#ifndef ARMY_VAMPIREABILITY_H
#define ARMY_VAMPIREABILITY_H

#include "Ability.h"
#include "../exceptions.h"

class VampireAbility : public Ability {
public:
    VampireAbility(Unit* owner);
    virtual ~VampireAbility();

    void attack(Unit* enemy);
    void counterAttack(Unit* enemy);
    void turnEnemy(Unit *enemy);
};

#endif //ARMY_VAMPIREABILITY_H
