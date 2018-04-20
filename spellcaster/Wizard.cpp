//
// Created by denysvysochanskyi on 17.04.18.
//

#include "Wizard.h"

Wizard::Wizard(const char* title, int hitPoints, int damage, int mana)
        : SpellCaster(title, hitPoints, damage, mana) {
        this->magicAbility = new WizardMagicAbility(this, fireBall);
        this->unitTypes = new UnitTypes(false, true);
}

Wizard::~Wizard() {}