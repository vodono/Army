    //
// Created by denysvysochanskyi on 27.03.18.
//

#ifndef ARMY_SOLDIER_H
#define ARMY_SOLDIER_H

#include "Unit.h"
#include "../ability/DefaultAbility.h"

class Soldier : public Unit {
public:
    Soldier(const char* title, int hitPoints, int damage);
    virtual ~Soldier();
};

#endif //ARMY_SOLDIER_H
