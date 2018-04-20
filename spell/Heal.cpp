//
// Created by denysvysochanskyi on 17.04.18.
//

#include "Heal.h"

Heal::Heal(int actionPoints, int cost, MagicBook* magicBook)
        : Spell(actionPoints, cost, magicBook) {
        this->isBattle = false;
}

Heal::~Heal() {}

void Heal::action(Unit* target, double actionModifyIndex) {
    target->addHitPoints((int)(this->getActionPoints() * actionModifyIndex));
}