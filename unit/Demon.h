    //
// Created by denysvysochanskyi on 27.03.18.
//

#ifndef ARMY_DEMON_H
#define ARMY_DEMON_H

#include "Unit.h"
#include "../ability/DemonAbility.h"

class Demon : public Unit {
public:
    Demon(const char* title, int hitPoints, int damage);
    virtual ~Demon();
};

#endif //ARMY_DEMON_H
