//
// Created by denysvysochanskyi on 09.04.18.
//

#include "WerewolfAbility.h"
#include "../state/WerewolfState.h"

WerewolfAbility::WerewolfAbility(Unit* owner) : Ability(owner) {}

WerewolfAbility::~WerewolfAbility() {}

void WerewolfAbility::attack(Unit* enemy) {
    Ability::attack(enemy);
}

void WerewolfAbility::turnEnemy(Unit* enemy) {
    this->owner->ensureIsAlive();

    if( !enemy->getIsTurnable() ) {
        throw NotAllowedToTurn();
    }

    enemy->changeAbility(new WerewolfAbility(enemy));
    enemy->changeUnitTypes(new UnitTypes(false, false));
}

void WerewolfAbility::turnMyself() {
    this->owner->ensureIsAlive();

    if ( this->owner->getIsWolf() ) {
        int newHp = (int) (this->owner->getHitPoints() / WOLF_RATE);
        int newHpLimit = (int) (this->owner->getHitPointsLimit() / WOLF_RATE);

        this->owner->changeState(new State(this->owner->getTitle(),
                                           newHpLimit,
                                           (int)(this->owner->getDamage() / WOLF_RATE)));

        this->owner->takeDamage(newHpLimit - newHp);
    } else {
        int newHp = (int) (this->owner->getHitPoints() * WOLF_RATE);
        int newHpLimit = (int) (this->owner->getHitPointsLimit() * WOLF_RATE);

        this->owner->changeState(new WerewolfState(this->owner->getTitle(),
                                                   newHpLimit,
                                                   (int) (this->owner->getDamage() * WOLF_RATE)));

        this->owner->takeDamage(newHpLimit - newHp);
    }
}