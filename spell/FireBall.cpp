//
// Created by denysvysochanskyi on 16.04.18.
//

#include "FireBall.h"

FireBall::FireBall(int actionPoints, int cost, MagicBook* magicBook)
        : Spell(actionPoints, cost, magicBook) {
    this->isBattle = true;
}

FireBall::~FireBall() {}

void FireBall::action(Unit* target, double actionModifyIndex) {
    target->takeMagicDamage((int)(this->getActionPoints() * actionModifyIndex));
}