//
// Created by denysvysochanskyi on 18.04.18.
//

#ifndef ARMY_WIZARDMAGICABILITY_H
#define ARMY_WIZARDMAGICABILITY_H

#include "MagicAbility.h"

#define WIZARD_RATE 0.5

class WizardMagicAbility : public MagicAbility {
public:
    WizardMagicAbility(SpellCaster* owner, spells spell);
    virtual ~WizardMagicAbility();

    virtual void cast(Unit* enemy);
};


#endif //ARMY_WIZARDMAGICABILITY_H
