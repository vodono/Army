//
// Created by denysvysochanskyi on 27.03.18.
//

#include "Soldier.h"

Soldier::Soldier(const char* title, int hitPoints, int damage) :
    Unit(title, hitPoints, damage) {
    this->ability = new DefaultAbility(this);
    this->unitTypes = new UnitTypes(false, true);
}

Soldier::~Soldier() {}
