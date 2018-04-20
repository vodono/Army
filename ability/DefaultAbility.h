//
// Created by denysvysochanskyi on 22.03.18.
//

#ifndef ARMY_DEFAULTABILITY_H
#define ARMY_DEFAULTABILITY_H

#include "Ability.h"

class DefaultAbility : public Ability {
public:
    DefaultAbility(Unit* owner);
    virtual ~DefaultAbility();

    virtual void attack(Unit* enemy);
};

#endif //ARMY_DEFAULTABILITY_H
