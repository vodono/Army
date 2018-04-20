//
// Created by denysvysochanskyi on 17.04.18.
//

#include "Pray.h"

Pray::Pray(int actionPoints, int cost, MagicBook* magicBook) : Spell(actionPoints, cost, magicBook) {
    this->isBattle = false;
}

Pray::~Pray() {}

void Pray::action(Unit* target, double actionModifyIndex) {
    target->addHitPoints((int)(this->getActionPoints() * actionModifyIndex));
}