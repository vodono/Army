//
// Created by denysvysochanskyi on 17.04.18.
//

#ifndef ARMY_LIGHTNING_H
#define ARMY_LIGHTNING_H

#include "Spell.h"

class MagicBook;

class Lightning : public Spell {
public:
    Lightning(int actionPoints, int cost, MagicBook* magicBook);
    virtual ~Lightning();

    virtual void action(Unit* target, double actionModifyIndex);
};


#endif //ARMY_LIGHTNING_H
