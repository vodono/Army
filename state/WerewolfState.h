//
// Created by denysvysochanskyi on 09.04.18.
//

#ifndef ARMY_WEREWOLFSTATE_H
#define ARMY_WEREWOLFSTATE_H

#include "State.h"

#define WOLF_RATE 1.2

class WerewolfState : public State {
public:
    WerewolfState(const char*, int hitPoints, int hitPointsLimit);
    virtual ~WerewolfState();

    int takeMagicDamage(int dmg);
};


#endif //ARMY_WEREWOLFSTATE_H
