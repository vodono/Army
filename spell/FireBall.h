//
// Created by denysvysochanskyi on 16.04.18.
//

#ifndef ARMY_FIREBALL_H
#define ARMY_FIREBALL_H

#include "Spell.h"
#include "MagicBook.h"

class MagicBook;

class FireBall : public Spell {
public:
    FireBall(int actionPoints, int cost, MagicBook* magicBook);
    virtual ~FireBall();

    virtual void action(Unit* target, double actionModifyIndex);
};


#endif //ARMY_FIREBALL_H
