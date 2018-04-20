//
// Created by denysvysochanskyi on 19.04.18.
//

#include "PriestMagicAbility.h"

PriestMagicAbility::PriestMagicAbility(SpellCaster* owner, spells spell)
        : MagicAbility(owner, spell) {}

PriestMagicAbility::~PriestMagicAbility() {}

void PriestMagicAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    if( !this->owner->getIsTurnable() ) {
        throw NotAllowedToCast();
    }

    this->owner->spendMana(this->spell->getCost());

    double actionModifyIndex;

    if ( !this->spell->getIsBattle() ) {
        actionModifyIndex = 1;
    } else if ( enemy->getIsUndead() ) {
        actionModifyIndex = UNDEAD_RATE;
    } else {
        actionModifyIndex = HEALER_RATE;
    }

    this->spell->action(enemy, actionModifyIndex);
}
