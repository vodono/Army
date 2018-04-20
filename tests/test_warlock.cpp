//
// Created by denysvysochanskyi on 18.04.18.
//

#include "catch.hpp"
#include "../spellcaster/Warlock.h"
#include "../unit/Soldier.h"
#include "../unit/Demon.h"
#include <string.h>

TEST_CASE( "Test Warlock class" ) {
    Warlock* warlock = new Warlock("Warlock", 100, 10, 100);

    REQUIRE( warlock->getHitPoints() == 100 );
    REQUIRE( warlock->getHitPointsLimit() == 100 );
    REQUIRE( warlock->getTitle() == "Warlock" );
    REQUIRE( warlock->getDamage() == 10 );
    REQUIRE( warlock->getIsUndead() == false );
    REQUIRE( warlock->getIsTurnable() == true );
    REQUIRE( warlock->getIsWolf() == false );
    REQUIRE( warlock->getMana() == 100 );
    REQUIRE( warlock->getManaLimit() == 100 );

    SECTION( "Warlock::takeDamage tests" ) {
        int damage = 10;
        int iterations = warlock->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            warlock->takeDamage(damage);
            int expectedHP = warlock->getHitPointsLimit() - damage * i;
            REQUIRE( warlock->getHitPoints() == expectedHP );
        }

        try {
            warlock->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( warlock->getHitPoints() == 0 );
        }
    }

    SECTION( "Warlock::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = warlock->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            warlock->takeMagicDamage(damage);
            int expectedHP = warlock->getHitPointsLimit() - damage * i;
            REQUIRE( warlock->getHitPoints() == expectedHP );
        }

        try {
            warlock->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( warlock->getHitPoints() == 0 );
        }
    }

    SECTION( "Warlock::addHitpoits tests" ) {
        warlock->takeDamage(50);
        REQUIRE( warlock->getHitPoints() == 50 );

        warlock->addHitPoints(40);
        REQUIRE( warlock->getHitPoints() == 90 );

        warlock->addHitPoints(10);
        REQUIRE( warlock->getHitPoints() == 100 );

        warlock->addHitPoints(10);
        REQUIRE( warlock->getHitPoints() == 100 );

        warlock->takeDamage(100);
        REQUIRE( warlock->getHitPoints() == 0 );

        try {
            warlock->addHitPoints(40);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE(warlock->getHitPoints() == 0);
        }
    }

    SECTION( "Warlock::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );

        warlock->attack(enemy);

        REQUIRE( warlock->getHitPoints() == 90 );
        REQUIRE( enemy->getHitPoints() == 140 );

        enemy->attack(warlock);

        REQUIRE( warlock->getHitPoints() == 70 );
        REQUIRE( enemy->getHitPoints() == 135 );

        enemy->takeDamage(130);
        REQUIRE( enemy->getHitPoints() == 5 );

        try {
            warlock->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( warlock->getHitPoints() == 70 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            warlock->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( warlock->getHitPoints() == 70 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }
    }

    SECTION ( "Warlock::turn test" ) {
        Soldier* soldier = new Soldier("Enemy", 150, 20);

        REQUIRE( soldier->getHitPoints() == 150 );
        REQUIRE( soldier->getHitPointsLimit() == 150 );
        REQUIRE( soldier->getTitle() == "Enemy" );
        REQUIRE( soldier->getDamage() == 20 );
        REQUIRE( soldier->getIsUndead() == false );
        REQUIRE( soldier->getIsTurnable() == true );
        REQUIRE( soldier->getIsWolf() == false );

        try {
            warlock->turnEnemy(soldier);
        } catch( NotAllowedToTurn obj ) {
            REQUIRE( soldier->getHitPoints() == 150 );
            REQUIRE( soldier->getHitPointsLimit() == 150 );
            REQUIRE( soldier->getTitle() == "Enemy" );
            REQUIRE( soldier->getDamage() == 20 );
            REQUIRE( soldier->getIsUndead() == false );
            REQUIRE( soldier->getIsTurnable() == true );
            REQUIRE( soldier->getIsWolf() == false );

        }

        REQUIRE( soldier->getHitPoints() == 150 );
        REQUIRE( soldier->getHitPointsLimit() == 150 );
        REQUIRE( soldier->getTitle() == "Enemy" );
        REQUIRE( soldier->getDamage() == 20 );
        REQUIRE( soldier->getIsUndead() == false );
        REQUIRE( soldier->getIsTurnable() == true );
        REQUIRE( soldier->getIsWolf() == false );

        try {
            warlock->turnMyself();
        } catch( NotAllowedToTurn obj) {
            REQUIRE( warlock->getHitPoints() == 100 );
            REQUIRE( warlock->getHitPointsLimit() == 100 );
            REQUIRE( warlock->getTitle() == "Warlock" );
            REQUIRE( warlock->getDamage() == 10 );
            REQUIRE( warlock->getIsUndead() == false );
            REQUIRE( warlock->getIsTurnable() == true );
            REQUIRE( warlock->getIsWolf() == false );
            REQUIRE( warlock->getMana() == 100 );
            REQUIRE( warlock->getManaLimit() == 100 );
        }
    }

    SECTION ( "Warlock::add spend mana test" ) {
        warlock->addMana(20);
        REQUIRE( warlock->getMana() == 100 );

        warlock->spendMana(40);
        REQUIRE( warlock->getMana() == 60 );

        warlock->addMana(20);
        REQUIRE( warlock->getMana() == 80 );

        try {
            warlock->spendMana(90);
        } catch ( OutOfManaException obj ) {
            REQUIRE( warlock->getMana() == 80 );
        }

        warlock->addMana(30);
        REQUIRE( warlock->getMana() == 100 );
    }

    SECTION ( "Warlock::casting test" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );

        warlock->cast(enemy);
        REQUIRE( enemy->getHitPoints() == 135 );
        REQUIRE( warlock->getMana() == 88 );

        warlock->changeSpell(pray);
        warlock->cast(enemy);
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( warlock->getMana() == 76 );

        warlock->spendMana(36);
        warlock->changeSpell(inferno);
        try {
            warlock->cast(enemy);
        } catch ( OutOfManaException obj ) {
            REQUIRE(enemy->getHitPoints() == 150);
            REQUIRE(warlock->getMana() == 40);
        }
    }

    SECTION ( "Warlock::evoke Demon test" ) {
        Demon* demon1 = warlock->evokeDemon();
        REQUIRE( demon1->getHitPoints() == 150 );
        REQUIRE( demon1->getHitPointsLimit() == 150 );
        REQUIRE( !strcmp(demon1->getTitle(), "Demon1") );
        REQUIRE( demon1->getDamage() == 20 );
        REQUIRE( demon1->getIsUndead() == true );
        REQUIRE( demon1->getIsTurnable() == true );
        REQUIRE( demon1->getIsWolf() == false );

        Demon* demon2 = warlock->evokeDemon();
        REQUIRE( demon2->getHitPoints() == 150 );
        REQUIRE( demon2->getHitPointsLimit() == 150 );
        REQUIRE( !strcmp(demon2->getTitle(), "Demon2") );
        REQUIRE( demon2->getDamage() == 20 );
        REQUIRE( demon2->getIsUndead() == true );
        REQUIRE( demon2->getIsTurnable() == true );
        REQUIRE( demon2->getIsWolf() == false );

        warlock->attack(demon1);
        REQUIRE( warlock->getHitPoints() == 85 );
        REQUIRE( demon1->getHitPoints() == 140 );

    }
}