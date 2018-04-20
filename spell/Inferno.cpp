//
// Created by denysvysochanskyi on 17.04.18.
//

#include "Inferno.h"

Inferno::Inferno(int actionPoints, int cost, MagicBook* magicBook) : Spell(actionPoints, cost, magicBook) {
    this->isBattle = true;
}

Inferno::~Inferno() {}

void Inferno::action(Unit* target, double actionModifyIndex) {
    target->takeMagicDamage((int)(this->getActionPoints() * actionModifyIndex));
}