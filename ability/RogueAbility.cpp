//
// Created by denysvysochanskyi on 27.03.18.
//

#include "RogueAbility.h"

RogueAbility::RogueAbility(Unit* owner): Ability(owner) {}

RogueAbility::~RogueAbility() {}

void RogueAbility::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());
}