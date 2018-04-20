//
// Created by denysvysochanskyi on 22.03.18.
//

#include "Ability.h"

Ability::Ability(Unit* owner): owner(owner) {}
Ability::~Ability() {}

void Ability::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());
    enemy->counterAttack(this->owner);
}

void Ability::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage() / COUNTER_ATTACK_RATE);
}

void Ability::turnEnemy(Unit *enemy) {
    this->owner->ensureIsAlive();
    if ( this->owner->getIsTurnable() ) {
        throw NotAllowedToTurn();
    }
}

void Ability::turnMyself() {
    this->owner->ensureIsAlive();
    throw NotAllowedToTurn();
}