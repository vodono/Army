//
// Created by denysvysochanskyi on 16.04.18.
//

#ifndef ARMY_SPELLCASTER_H
#define ARMY_SPELLCASTER_H

#include "../unit/Unit.h"
#include "../state/MagicState.h"
#include "../magicAbility/MagicAbility.h"
#include "../ability/DefaultAbility.h"
#include "../spell/MagicBook.h"
#include "../unit/Demon.h"

class MagicAbility;

class SpellCaster : public Unit {
protected:
    MagicState* magicState;
    MagicAbility* magicAbility;

public:
    SpellCaster(const char* title, int hitPoints, int damage, int mana);
    virtual ~SpellCaster();

    int getMana() const;
    int getManaLimit() const;

    void addMana(int extra);
    void spendMana(int cost);

    void changeSpell(spells newSpell);
    virtual void cast(Unit* enemy);
    virtual Demon* evokeDemon();
};


#endif //ARMY_SPELLCASTER_H
