//
// Created by denysvysochanskyi on 21.03.18.
//

#include "State.h"

State::State(const char* title, int hitPoints, int damage) {
    this->title = title;
    this->hitPoints = hitPoints;
    this->hitPointsLimit = hitPoints;
    this->damage = damage;
    this->isWolf = false;
}

State::~State() {}

void State::ensureIsAlive() {
    if ( this->hitPoints == 0 ) {
        throw OutOfHitPointsException();
    }
}

const char* State::getTitle() const {
    return this->title;
}

int State::getHitPoints() const {
    return this->hitPoints;
}

int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

int State::getDamage() const {
    return this->damage;
}

bool State::getIsWolf() const {
    return this->isWolf;
}

int State::addHitPoints(int hp) {
    this->ensureIsAlive();

    int lack = this->hitPointsLimit - this->hitPoints;

    if ( hp > lack ) {
        this->hitPoints = this->hitPointsLimit;
        return lack;
    }

    this->hitPoints += hp;
    return hp;
}

int State::_takeDamage(int dmg) {
    this->ensureIsAlive();

    if ( dmg > this->hitPoints ) {
        int temp = this->hitPoints;

        this->hitPoints = 0;
        return temp;
    }
    this->hitPoints -= dmg;
    return dmg;
}

int State::takeDamage(int dmg) {
    return this->_takeDamage(dmg);

}
int State::takeMagicDamage(int dmg) {
    return this->_takeDamage(dmg);
}

void State::setIsWolf(bool isWolf) {
    this->isWolf = isWolf;
}
