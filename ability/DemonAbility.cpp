//
// Created by denysvysochanskyi on 22.03.18.
//

#include "DemonAbility.h"

DemonAbility::DemonAbility(Unit* owner) : Ability(owner) {}
DemonAbility::~DemonAbility() {}

void DemonAbility::attack(Unit* enemy) {
    Ability::attack(enemy);
}

void DemonAbility::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage() / COUNTER_ATTACK_RATE);
    enemy->takeDamage(this->owner->getDamage() / COUNTER_ATTACK_RATE / 2);
}

