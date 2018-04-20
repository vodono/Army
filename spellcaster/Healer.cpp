//
// Created by denysvysochanskyi on 19.04.18.
//

#include "Healer.h"

Healer::Healer(const char* title, int hitPoints, int damage, int mana)
        : SpellCaster(title, hitPoints, damage, mana) {
    this->magicAbility = new HealerMagicAbility(this, heal);
    this->unitTypes = new UnitTypes(false, true);
}

Healer::~Healer() {}