//
// Created by denysvysochanskyi on 18.04.18.
//

#include "WizardMagicAbility.h"

WizardMagicAbility::WizardMagicAbility(SpellCaster* owner, spells spell)
        : MagicAbility(owner, spell) {}

WizardMagicAbility::~WizardMagicAbility() {}

void WizardMagicAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    if( !this->owner->getIsTurnable() ) {
        throw NotAllowedToCast();
    }
    this->owner->spendMana(this->spell->getCost());

    double actionModifyIndex;

    if ( this->spell->getIsBattle() ) {
        actionModifyIndex = 1;
    } else {
        actionModifyIndex = WIZARD_RATE;
    }
    this->spell->action(enemy, actionModifyIndex);
}