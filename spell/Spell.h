//
// Created by denysvysochanskyi on 16.04.18.
//

#ifndef ARMY_SPELL_H
#define ARMY_SPELL_H

#include "../unit/Unit.h"

class MagicBook;

class Spell {
protected:
    int actionPoints;
    int cost;
    bool isBattle;
    MagicBook* magicBook;

public:
    Spell(int actionPoints, int cost, MagicBook* magicBook);
    virtual ~Spell();

    int getActionPoints();
    int getCost();
    int getIsBattle();
    MagicBook* getMagicBook();

    virtual void action(Unit* target, double actionModifyIndex) = 0;
};


#endif //ARMY_SPELL_H
