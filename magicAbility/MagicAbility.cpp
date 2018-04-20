//
// Created by denysvysochanskyi on 12.04.18.
//

#include "MagicAbility.h"
#include "../exceptions.h"

MagicAbility::MagicAbility(SpellCaster* owner, spells spell)
        : owner(owner) {
    MagicBook* magicBook = MagicBook::Instance();
    this->spell = magicBook->getSpell(spell);
}

MagicAbility::~MagicAbility() {}

void MagicAbility::changeSpell(spells newSpell) {
    this->spell = this->spell->getMagicBook()->getSpell(newSpell);
}

void MagicAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    if( !this->owner->getIsTurnable() ) {
        throw NotAllowedToCast();
    }
    this->owner->spendMana(this->spell->getCost());
    int actionModifyIndex = 1;
    this->spell->action(enemy, actionModifyIndex);
}

Demon* MagicAbility::evokeDemon() {}