//
// Created by denysvysochanskyi on 19.04.18.
//

#ifndef ARMY_PRIESTMAGICABILITY_H
#define ARMY_PRIESTMAGICABILITY_H

#include "MagicAbility.h"

#define HEALER_RATE 0.5
#define UNDEAD_RATE 2

class PriestMagicAbility : public MagicAbility {
public:
    PriestMagicAbility(SpellCaster* owner, spells spell);
    virtual ~PriestMagicAbility();

    virtual void cast(Unit* enemy);
};


#endif //ARMY_PRIESTMAGICABILITY_H
