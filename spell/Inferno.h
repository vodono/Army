//
// Created by denysvysochanskyi on 17.04.18.
//

#ifndef ARMY_INFERNO_H
#define ARMY_INFERNO_H

#include "Spell.h"

class MagicBook;

class Inferno : public Spell {
public:
    Inferno(int actionPoints, int cost, MagicBook* magicBook);
    virtual ~Inferno();

    virtual void action(Unit* target, double actionModifyIndex);
};


#endif //ARMY_INFERNO_H
