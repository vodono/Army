//
// Created by denysvysochanskyi on 21.03.18.
//

#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../exceptions.h"

class State {
protected:
    const char* title;
    int hitPoints;
    int hitPointsLimit;
    int damage;
    bool isWolf;

    int _takeDamage(int dmg);
    void setIsWolf(bool isWolf);

public:
    State(const char* title, int hitPoints, int damage);
    virtual ~State();

    void ensureIsAlive();

    const char* getTitle() const;
    int getHitPoints() const;
    int getHitPointsLimit() const;
    int getDamage() const;
    bool getIsWolf() const;

    int addHitPoints(int hp);
    virtual int takeDamage(int dmg);
    virtual int takeMagicDamage(int dmg);
};

#endif //STATE_H
