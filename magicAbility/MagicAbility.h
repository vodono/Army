//
// Created by denysvysochanskyi on 12.04.18.
//

#ifndef ARMY_MAGICABILITY_H
#define ARMY_MAGICABILITY_H

#include "../spell/Spell.h"
#include "../spellcaster/SpellCaster.h"
#include "../spell/MagicBook.h"

class SpellCaster;
class Unit;
class Demon;

class MagicAbility {
protected:
    SpellCaster* owner;
    Spell* spell;

public:
    MagicAbility(SpellCaster* owner, spells spell);
    virtual ~MagicAbility();

    void changeSpell(spells newSpell);
    virtual void cast(Unit* enemy);
    virtual Demon* evokeDemon();
};


#endif //ARMY_MAGICABILITY_H
