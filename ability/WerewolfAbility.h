//
// Created by denysvysochanskyi on 09.04.18.
//

#ifndef ARMY_WEREWOLFABILITY_H
#define ARMY_WEREWOLFABILITY_H

#include "Ability.h"

#define WOLF_RATE 1.2

class WerewolfAbility : public Ability {
public:
    WerewolfAbility(Unit* owner);
    virtual ~WerewolfAbility();

    virtual void attack(Unit* enemy);
    void turnEnemy(Unit* enemy);
    void turnMyself();
};


#endif //ARMY_WEREWOLFABILITY_H
