//
// Created by denysvysochanskyi on 19.04.18.
//

#include "HealerMagicAbility.h"

HealerMagicAbility::HealerMagicAbility(SpellCaster* owner, spells spell)
        : MagicAbility(owner, spell) {}

HealerMagicAbility::~HealerMagicAbility() {}

void HealerMagicAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    if( !this->owner->getIsTurnable() ) {
        throw NotAllowedToCast();
    }
    this->owner->spendMana(this->spell->getCost());

    double actionModifyIndex;

    if ( !this->spell->getIsBattle() ) {
        actionModifyIndex = 1;
    } else {
        actionModifyIndex = HEALER_RATE;
    }
    this->spell->action(enemy, actionModifyIndex);
}