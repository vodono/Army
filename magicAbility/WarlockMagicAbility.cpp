//
// Created by denysvysochanskyi on 19.04.18.
//

#include "WarlockMagicAbility.h"
#include "../unit/Demon.h"
#include <string>
#include <cstring>

WarlockMagicAbility::WarlockMagicAbility(SpellCaster* owner, spells spell)
        : MagicAbility(owner, spell) {}

WarlockMagicAbility::~WarlockMagicAbility() {}

void WarlockMagicAbility::cast(Unit* enemy) {
    this->owner->ensureIsAlive();
    if( !this->owner->getIsTurnable() ) {
        throw NotAllowedToCast();
    }
    this->owner->spendMana(this->spell->getCost());

    double actionModifyIndex = 1;

    this->spell->action(enemy, actionModifyIndex);
}

Demon* WarlockMagicAbility::evokeDemon() {
    static int demonN = 1;

    std::string name = "Demon";
    name += std::to_string(demonN);

    char* title = new char [name.length()+1];
    strcpy(title, name.c_str());

    demonN += 1;

    return new Demon(title, 150, 20);
}
