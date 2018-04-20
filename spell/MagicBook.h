//
// Created by denysvysochanskyi on 18.04.18.
//

#ifndef ARMY_MAGICBOOK_H
#define ARMY_MAGICBOOK_H

#include <iostream>
#include <map>
#include "Spell.h"
#include "FireBall.h"
#include "Lightning.h"
#include "Inferno.h"
#include "Heal.h"
#include "Pray.h"

class Spell;
class FireBall;

typedef enum {
    fireBall,
    lightning,
    inferno,
    heal,
    pray,
} spells;

class MagicBook {
private:
    std::map<spells, Spell*> spellsMap;
    static MagicBook* _magicBook;

    MagicBook();
    ~MagicBook();
    MagicBook(const MagicBook*);
    MagicBook* operator= (const MagicBook*);
public:
    static MagicBook* Instance();
    Spell* getSpell(spells sp);
};

#endif //ARMY_MAGICBOOK_H
