//
// Created by denysvysochanskyi on 17.04.18.
//

#include "Lightning.h"

Lightning::Lightning(int actionPoints, int cost, MagicBook* magicBook)
        : Spell(actionPoints, cost, magicBook) {
        this->isBattle = true;
}

Lightning::~Lightning() {}

void Lightning::action(Unit* target, double actionModifyIndex) {
    target->takeMagicDamage((int)(this->getActionPoints() * actionModifyIndex));
}