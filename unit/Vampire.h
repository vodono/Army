//
// Created by denysvysochanskyi on 27.03.18.
//

#ifndef ARMY_VAMPIRE_H
#define ARMY_VAMPIRE_H

#include "Unit.h"
#include "../ability/VampireAbility.h"

class Vampire : public Unit {
public:
    Vampire(const char* title, int hitPoints, int damage);
    virtual ~Vampire();

};


#endif //ARMY_VAMPIRE_H
