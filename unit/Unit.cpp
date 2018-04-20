//
// Created by denysvysochanskyi on 22.03.18.
//

#include "Unit.h"

Unit::Unit(const char* title, int hitPoints, int damage)
        : state(new State(title, hitPoints, damage)) {}

Unit::~Unit() {
    delete (this->state);
    delete (this->ability);
    delete (this->unitTypes);
}

void Unit::ensureIsAlive() {
    this->state->ensureIsAlive();
}

const char* Unit::getTitle() const {
    return this->state->getTitle();
}

int Unit::getHitPoints() const {
    return this->state->getHitPoints();
}

int Unit::getHitPointsLimit() const {
    return this->state->getHitPointsLimit();
}

int Unit::getDamage() const {
    return this->state->getDamage();
}

bool Unit::getIsUndead() const {
    return this->unitTypes->getIsUndead();
}

bool Unit::getIsTurnable() const {
    return this->unitTypes->getIsTurnable();
}

bool Unit::getIsWolf() const {
    return this->state->getIsWolf();
}

int Unit::addHitPoints(int hp) {
    return this->state->addHitPoints(hp);
}

int Unit::takeDamage(int dmg) {
    return this->state->takeDamage(dmg);
}

int Unit::takeMagicDamage(int dmg) {
    return this->state->takeMagicDamage(dmg);
}

void Unit::attack(Unit* enemy) {
    this->ability->attack(enemy);
}

void Unit::counterAttack(Unit* enemy) {
    this->ability->counterAttack(enemy);
}

void Unit::turnEnemy(Unit* enemy) {
    this->ability->turnEnemy(enemy);
}

void Unit::turnMyself() {
    this->ability->turnMyself();
}

void Unit::changeAbility(Ability* newAbility) {
    delete(this->ability);
    this->ability = newAbility;
}

void Unit::changeUnitTypes(UnitTypes* newUnitTypes) {
    delete(this->unitTypes);
    this->unitTypes = newUnitTypes;
}

void Unit::changeState(State* newState) {
    delete(this->state);
    this->state = newState;
}
