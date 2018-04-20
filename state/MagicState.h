//
// Created by denysvysochanskyi on 21.03.18.
//

#ifndef ARMY_MAGICSTATE_H
#define ARMY_MAGICSTATE_H

#include <iostream>
#include "../exceptions.h"

class MagicState {
protected:
    int mana;
    int manaLimit;

public:
    MagicState(int mana);
    virtual ~MagicState();

    int getMana() const;
    int getManaLimit() const;

    void addMana(int extra);
    void spendMana(int cost);
};


#endif //ARMY_MAGICSTATE_H
