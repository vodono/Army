//
// Created by denysvysochanskyi on 27.03.18.
//

#include "Demon.h"

Demon::Demon(const char* title, int hitPoints, int damage) :
    Unit(title, hitPoints, damage) {
    this->ability = new DemonAbility(this);
    this->unitTypes = new UnitTypes(true, true);
}

Demon::~Demon() {}
