//
// Created by denysvysochanskyi on 19.04.18.
//

#ifndef ARMY_HEALERMAGICABILITY_H
#define ARMY_HEALERMAGICABILITY_H

#include "MagicAbility.h"

#define HEALER_RATE 0.5

class HealerMagicAbility : public MagicAbility {
public:
    HealerMagicAbility(SpellCaster* owner, spells spell);
    virtual ~HealerMagicAbility();

    virtual void cast(Unit* enemy);
};


#endif //ARMY_HEALERMAGICABILITY_H
