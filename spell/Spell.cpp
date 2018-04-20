//
// Created by denysvysochanskyi on 16.04.18.
//

#include "Spell.h"

Spell::Spell(int actionPoints, int cost, MagicBook* magicBook)
        : actionPoints(actionPoints), cost(cost), magicBook(magicBook) {}

Spell::~Spell() {}

int Spell::getActionPoints() {
    return this->actionPoints;
}

int Spell::getCost() {
    return this->cost;
}

int Spell::getIsBattle() {
    return this->isBattle;
}

MagicBook* Spell::getMagicBook() {
    return this->magicBook;
}