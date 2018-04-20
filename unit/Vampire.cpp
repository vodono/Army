//
// Created by denysvysochanskyi on 27.03.18.
//

#include "Vampire.h"

Vampire::Vampire(const char* title, int hitPoints, int damage) :
    Unit(title, hitPoints, damage) {
    this->ability = new VampireAbility(this);
    this->unitTypes = new UnitTypes(true, false);
}

Vampire::~Vampire() {}
