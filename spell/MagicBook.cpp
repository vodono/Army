//
// Created by denysvysochanskyi on 17.04.18.
//

#include "MagicBook.h"

MagicBook::MagicBook() {
    _magicBook = this;
    spellsMap = {
            {fireBall,  new FireBall(30, 30, _magicBook)},
            {lightning, new Lightning(15, 12, _magicBook)},
            {inferno,   new Inferno(40, 45, _magicBook)},
            {heal,      new Heal(30, 30, _magicBook)},
            {pray,      new Pray(15, 12, _magicBook)}
    };
}

MagicBook::~MagicBook() {}

MagicBook::MagicBook(const MagicBook*) {}

MagicBook* MagicBook::operator= (const MagicBook*) {}

MagicBook* MagicBook::Instance() {
    if ( !_magicBook ) {
        _magicBook = new MagicBook();
    }

    return _magicBook;
}

Spell* MagicBook::getSpell (spells spell) {
    return this->spellsMap.at(spell);
}

MagicBook* MagicBook::_magicBook = nullptr;