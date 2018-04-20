//
// Created by denysvysochanskyi on 17.04.18.
//

#ifndef ARMY_WIZARD_H
#define ARMY_WIZARD_H

#include "SpellCaster.h"
#include "../magicAbility/WizardMagicAbility.h"

class Wizard : public SpellCaster {
public:
    Wizard(const char* title, int hitPoints, int damage, int mana);
    virtual ~Wizard();
};


#endif //ARMY_WIZARD_H
