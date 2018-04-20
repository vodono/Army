//
// Created by denysvysochanskyi on 27.03.18.
//

#include "Werewolf.h"

Werewolf::Werewolf(const char* title, int hitPoints, int damage) :
    Unit(title, hitPoints, damage) {
    this->ability = new WerewolfAbility(this);
    this->unitTypes = new UnitTypes(false, false);
}

Werewolf::~Werewolf() {}
