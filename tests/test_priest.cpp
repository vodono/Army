//
// Created by denysvysochanskyi on 18.04.18.
//

#include "catch.hpp"
#include "../spellcaster/Priest.h"
#include "../unit/Soldier.h"
#include "../unit/Vampire.h"

TEST_CASE( "Test Priest class" ) {
    Priest* priest = new Priest("Priest", 100, 10, 100);

    REQUIRE( priest->getHitPoints() == 100 );
    REQUIRE( priest->getHitPointsLimit() == 100 );
    REQUIRE( priest->getTitle() == "Priest" );
    REQUIRE( priest->getDamage() == 10 );
    REQUIRE( priest->getIsUndead() == false );
    REQUIRE( priest->getIsTurnable() == true );
    REQUIRE( priest->getIsWolf() == false );
    REQUIRE( priest->getMana() == 100 );
    REQUIRE( priest->getManaLimit() == 100 );

    SECTION( "Priest::takeDamage tests" ) {
        int damage = 10;
        int iterations = priest->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            priest->takeDamage(damage);
            int expectedHP = priest->getHitPointsLimit() - damage * i;
            REQUIRE( priest->getHitPoints() == expectedHP );
        }

        try {
            priest->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( priest->getHitPoints() == 0 );
        }
    }

    SECTION( "Priest::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = priest->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            priest->takeMagicDamage(damage);
            int expectedHP = priest->getHitPointsLimit() - damage * i;
            REQUIRE( priest->getHitPoints() == expectedHP );
        }

        try {
            priest->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( priest->getHitPoints() == 0 );
        }
    }

    SECTION( "Priest::addHitpoits tests" ) {
        priest->takeDamage(50);
        REQUIRE( priest->getHitPoints() == 50 );

        priest->addHitPoints(40);
        REQUIRE( priest->getHitPoints() == 90 );

        priest->addHitPoints(10);
        REQUIRE( priest->getHitPoints() == 100 );

        priest->addHitPoints(10);
        REQUIRE( priest->getHitPoints() == 100 );

        priest->takeDamage(100);
        REQUIRE( priest->getHitPoints() == 0 );

        try {
            priest->addHitPoints(40);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE(priest->getHitPoints() == 0);
        }
    }

    SECTION( "Priest::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );

        priest->attack(enemy);

        REQUIRE( priest->getHitPoints() == 90 );
        REQUIRE( enemy->getHitPoints() == 140 );

        enemy->attack(priest);

        REQUIRE( priest->getHitPoints() == 70 );
        REQUIRE( enemy->getHitPoints() == 135 );

        enemy->takeDamage(130);
        REQUIRE( enemy->getHitPoints() == 5 );

        try {
            priest->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( priest->getHitPoints() == 70 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            priest->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( priest->getHitPoints() == 70 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }
    }

    SECTION ( "Priest::turn test" ) {
        Soldier* soldier = new Soldier("Enemy", 150, 20);

        REQUIRE( soldier->getHitPoints() == 150 );
        REQUIRE( soldier->getHitPointsLimit() == 150 );
        REQUIRE( soldier->getTitle() == "Enemy" );
        REQUIRE( soldier->getDamage() == 20 );
        REQUIRE( soldier->getIsUndead() == false );
        REQUIRE( soldier->getIsTurnable() == true );
        REQUIRE( soldier->getIsWolf() == false );

        try {
            priest->turnEnemy(soldier);
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
            priest->turnMyself();
        } catch( NotAllowedToTurn obj) {
            REQUIRE( priest->getHitPoints() == 100 );
            REQUIRE( priest->getHitPointsLimit() == 100 );
            REQUIRE( priest->getTitle() == "Priest" );
            REQUIRE( priest->getDamage() == 10 );
            REQUIRE( priest->getIsUndead() == false );
            REQUIRE( priest->getIsTurnable() == true );
            REQUIRE( priest->getIsWolf() == false );
            REQUIRE( priest->getMana() == 100 );
            REQUIRE( priest->getManaLimit() == 100 );
        }
    }

    SECTION ( "Priest::add spend mana test" ) {
        priest->addMana(20);
        REQUIRE( priest->getMana() == 100 );

        priest->spendMana(40);
        REQUIRE( priest->getMana() == 60 );

        priest->addMana(20);
        REQUIRE( priest->getMana() == 80 );

        try {
            priest->spendMana(90);
        } catch ( OutOfManaException obj ) {
            REQUIRE( priest->getMana() == 80 );
        }

        priest->addMana(30);
        REQUIRE( priest->getMana() == 100 );
    }

    SECTION ( "Priest::casting test" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);
        Vampire* vampire = new Vampire("Vampire", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );

        enemy->takeDamage(30);
        REQUIRE( enemy->getHitPoints() == 120 );
        priest->cast(enemy);
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( priest->getMana() == 70 );

        priest->changeSpell(fireBall);
        priest->cast(enemy);
        REQUIRE( enemy->getHitPoints() == 135 );
        REQUIRE( priest->getMana() == 40 );

        priest->changeSpell(inferno);
        try {
            priest->cast(enemy);
        } catch ( OutOfManaException obj ) {
            REQUIRE(enemy->getHitPoints() == 135);
            REQUIRE(priest->getMana() == 40);
        }

        priest->addMana(60);
        REQUIRE ( priest->getMana() == 100 );
        REQUIRE ( vampire->getHitPoints() == 150 );

        priest->cast(vampire);
        REQUIRE ( priest->getMana() == 55 );
        REQUIRE ( vampire->getHitPoints() == 70 );
    }
}