//
// Created by denysvysochanskyi on 22.03.18.
//

#ifndef ARMY_DEMONABILITY_H
#define ARMY_DEMONABILITY_H

#include "Ability.h"

class DemonAbility : public Ability {
public:
    DemonAbility(Unit* owner);
    virtual ~DemonAbility();

    virtual void attack(Unit* enemy);
    virtual void counterAttack(Unit* enemy);
};

#endif //ARMY_DEMONABILITY_H
