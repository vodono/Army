//
// Created by denysvysochanskyi on 09.04.18.
//

#include "WerewolfState.h"

WerewolfState::WerewolfState(const char* title, int hitPoints, int hitPointsLimit) :
        State(title, hitPoints, hitPointsLimit) {
    this->setIsWolf(true);
}

WerewolfState::~WerewolfState() {}

int WerewolfState::takeMagicDamage(int dmg) {
    if( this->isWolf ) {
        return State::takeMagicDamage(dmg * WOLF_RATE);
    }
    return State::takeMagicDamage(dmg);
}