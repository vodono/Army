//
// Created by denysvysochanskyi on 27.03.18.
//

#include "Rogue.h"

Rogue::Rogue(const char* title, int hitPoints, int damage):
    Unit(title, hitPoints, damage) {
        this->ability = new RogueAbility(this);
        this->unitTypes = new UnitTypes(false, true);
    }

Rogue::~Rogue() {}
