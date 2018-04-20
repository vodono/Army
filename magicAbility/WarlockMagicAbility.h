//
// Created by denysvysochanskyi on 19.04.18.
//

#ifndef ARMY_WARLOCK_MAGIC_ABILITY_H
#define ARMY_WARLOCK_MAGIC_ABILITY_H

#include "MagicAbility.h"

class WarlockMagicAbility : public MagicAbility {
public:
    WarlockMagicAbility(SpellCaster* owner, spells spell);
    virtual ~WarlockMagicAbility();

    virtual void cast(Unit* enemy);

    Demon* evokeDemon() override;
};


#endif //ARMY_WARLOCK_MAGIC_ABILITY_H
