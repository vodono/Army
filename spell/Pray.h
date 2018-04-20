//
// Created by denysvysochanskyi on 17.04.18.
//

#ifndef ARMY_PRAY_H
#define ARMY_PRAY_H

#include "Spell.h"

class MagicBook;

class Pray : public Spell {
public:
    Pray(int actionPoints, int cost, MagicBook* magicBook);
    virtual ~Pray();

    virtual void action(Unit* target, double actionModifyIndex);
};


#endif //ARMY_PRAY_H
