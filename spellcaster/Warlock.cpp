//
// Created by denysvysochanskyi on 19.04.18.
//

#include "Warlock.h"

Warlock::Warlock(const char* title, int hitPoints, int damage, int mana)
        : SpellCaster(title, hitPoints, damage, mana) {
    this->magicAbility  = new WarlockMagicAbility(this, lightning);
    this->unitTypes     = new UnitTypes(false, true);
}

Warlock::~Warlock() {}