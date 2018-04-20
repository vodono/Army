//
// Created by denysvysochanskyi on 27.03.18.
//

#include "VampireAbility.h"

#define HP_BACK_RATE 3

VampireAbility::VampireAbility(Unit* owner) : Ability(owner) {}

VampireAbility::~VampireAbility() {}

void VampireAbility::attack(Unit* enemy) {
    this->owner->ensureIsAlive();

    int damageActual = enemy->takeDamage(this->owner->getDamage());
    this->owner->addHitPoints( damageActual / HP_BACK_RATE );

    enemy->counterAttack(this->owner);
}

void VampireAbility::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();

    int damageActual = enemy->takeDamage(this->owner->getDamage() / COUNTER_ATTACK_RATE);
    this->owner->addHitPoints( damageActual / HP_BACK_RATE );
}

void VampireAbility::turnEnemy(Unit *enemy) {
    this->owner->ensureIsAlive();

    if( !enemy->getIsTurnable() ) {
        throw NotAllowedToTurn();
    }

    enemy->changeAbility(new VampireAbility(enemy));
    enemy->changeUnitTypes(new UnitTypes(true, false));
}