//
// Created by denysvysochanskyi on 16.04.18.
//

#include "SpellCaster.h"


SpellCaster::SpellCaster(const char* title, int hitPoints, int damage, int mana)
        : Unit(title, hitPoints, damage), magicState(new MagicState(mana)) {
    this->ability = new DefaultAbility(this);
}

SpellCaster::~SpellCaster() {
    delete(this->ability);
    delete(this->magicAbility);
    delete(this->magicState);
}

int SpellCaster::getMana() const {
    return this->magicState->getMana();
}

int SpellCaster::getManaLimit() const {
    return this->magicState->getManaLimit();
}

void SpellCaster::addMana(int extra) {
    this->magicState->addMana(extra);
}

void SpellCaster::spendMana(int cost) {
    this->magicState->spendMana(cost);
}

void SpellCaster::changeSpell(spells newSpell) {
    this->magicAbility->changeSpell(newSpell);
}

void SpellCaster::cast(Unit* enemy) {
    this->magicAbility->cast(enemy);
}

Demon* SpellCaster::evokeDemon() {
    this->magicAbility->evokeDemon();
}