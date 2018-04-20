//
// Created by denysvysochanskyi on 27.03.18.
//

#ifndef ARMY_ROGUEABILITY_H
#define ARMY_ROGUEABILITY_H

#include "Ability.h"

class RogueAbility : public Ability {
public:
    RogueAbility(Unit* owner);
    virtual ~RogueAbility();

    virtual void attack(Unit* enemy);
};

#endif //ARMY_ROGUEABILITY_H
