//
// Created by denysvysochanskyi on 17.04.18.
//

#ifndef ARMY_HEAL_H
#define ARMY_HEAL_H

#include "Spell.h"

class MagicBook;

class Heal : public Spell {
public:
    Heal(int actionPoints, int cost, MagicBook* magicBook);
    virtual ~Heal();

    virtual void action(Unit* target, double actionModifyIndex);
};


#endif //ARMY_HEAL_H
