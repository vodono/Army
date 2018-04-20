//
// Created by denysvysochanskyi on 22.03.18.
//

#ifndef ARMY_UNIT_H
#define ARMY_UNIT_H

#include "../state/State.h"
#include "../ability/Ability.h"
#include "../unitTypes/UnitTypes.h"

class Ability;
class UnitTypes;
class State;

class Unit {
protected:
    State* state;
    Ability* ability;
    UnitTypes* unitTypes;

public:
    Unit(const char* title, int hitPoints, int damage);
    virtual ~Unit();

    void ensureIsAlive();

    const char* getTitle() const;
    int getHitPoints() const;
    int getHitPointsLimit() const;
    int getDamage() const;
    bool getIsUndead() const;
    bool getIsTurnable() const;
    bool getIsWolf() const;

    int addHitPoints(int hp);
    virtual int takeDamage(int dmg);
    virtual int takeMagicDamage(int dmg);

    virtual void attack(Unit* enemy);
    virtual void counterAttack(Unit* enemy);

    virtual void turnEnemy(Unit* enemy);
    virtual void turnMyself();

    virtual void changeAbility(Ability* newAbility);
    virtual void changeUnitTypes(UnitTypes* newUnitTypes);
    virtual void changeState(State* newState);
};


#endif //ARMY_UNIT_H
