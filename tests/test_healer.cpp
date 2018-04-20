//
// Created by denysvysochanskyi on 18.04.18.
//

#include "catch.hpp"
#include "../spellcaster/Healer.h"
#include "../unit/Soldier.h"

TEST_CASE( "Test Healer class" ) {
    Healer* healer = new Healer("Healer", 100, 10, 100);

    REQUIRE( healer->getHitPoints() == 100 );
    REQUIRE( healer->getHitPointsLimit() == 100 );
    REQUIRE( healer->getTitle() == "Healer" );
    REQUIRE( healer->getDamage() == 10 );
    REQUIRE( healer->getIsUndead() == false );
    REQUIRE( healer->getIsTurnable() == true );
    REQUIRE( healer->getIsWolf() == false );
    REQUIRE( healer->getMana() == 100 );
    REQUIRE( healer->getManaLimit() == 100 );

    SECTION( "Healer::takeDamage tests" ) {
        int damage = 10;
        int iterations = healer->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            healer->takeDamage(damage);
            int expectedHP = healer->getHitPointsLimit() - damage * i;
            REQUIRE( healer->getHitPoints() == expectedHP );
        }

        try {
            healer->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( healer->getHitPoints() == 0 );
        }
    }

    SECTION( "Healer::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = healer->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            healer->takeMagicDamage(damage);
            int expectedHP = healer->getHitPointsLimit() - damage * i;
            REQUIRE( healer->getHitPoints() == expectedHP );
        }

        try {
            healer->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( healer->getHitPoints() == 0 );
        }
    }

    SECTION( "Healer::addHitpoits tests" ) {
        healer->takeDamage(50);
        REQUIRE( healer->getHitPoints() == 50 );

        healer->addHitPoints(40);
        REQUIRE( healer->getHitPoints() == 90 );

        healer->addHitPoints(10);
        REQUIRE( healer->getHitPoints() == 100 );

        healer->addHitPoints(10);
        REQUIRE( healer->getHitPoints() == 100 );

        healer->takeDamage(100);
        REQUIRE( healer->getHitPoints() == 0 );

        try {
            healer->addHitPoints(40);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE(healer->getHitPoints() == 0);
        }
    }

    SECTION( "Healer::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );

        healer->attack(enemy);

        REQUIRE( healer->getHitPoints() == 90 );
        REQUIRE( enemy->getHitPoints() == 140 );

        enemy->attack(healer);

        REQUIRE( healer->getHitPoints() == 70 );
        REQUIRE( enemy->getHitPoints() == 135 );

        enemy->takeDamage(130);
        REQUIRE( enemy->getHitPoints() == 5 );

        try {
            healer->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( healer->getHitPoints() == 70 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            healer->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( healer->getHitPoints() == 70 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }
    }

    SECTION ( "Healer::turn test" ) {
        Soldier* soldier = new Soldier("Enemy", 150, 20);

        REQUIRE( soldier->getHitPoints() == 150 );
        REQUIRE( soldier->getHitPointsLimit() == 150 );
        REQUIRE( soldier->getTitle() == "Enemy" );
        REQUIRE( soldier->getDamage() == 20 );
        REQUIRE( soldier->getIsUndead() == false );
        REQUIRE( soldier->getIsTurnable() == true );
        REQUIRE( soldier->getIsWolf() == false );

        try {
            healer->turnEnemy(soldier);
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
            healer->turnMyself();
        } catch( NotAllowedToTurn obj) {
            REQUIRE( healer->getHitPoints() == 100 );
            REQUIRE( healer->getHitPointsLimit() == 100 );
            REQUIRE( healer->getTitle() == "Healer" );
            REQUIRE( healer->getDamage() == 10 );
            REQUIRE( healer->getIsUndead() == false );
            REQUIRE( healer->getIsTurnable() == true );
            REQUIRE( healer->getIsWolf() == false );
            REQUIRE( healer->getMana() == 100 );
            REQUIRE( healer->getManaLimit() == 100 );
        }
    }

    SECTION ( "Healer::add spend mana test" ) {
        healer->addMana(20);
        REQUIRE( healer->getMana() == 100 );

        healer->spendMana(40);
        REQUIRE( healer->getMana() == 60 );

        healer->addMana(20);
        REQUIRE( healer->getMana() == 80 );

        try {
            healer->spendMana(90);
        } catch ( OutOfManaException obj ) {
            REQUIRE( healer->getMana() == 80 );
        }

        healer->addMana(30);
        REQUIRE( healer->getMana() == 100 );
    }

    SECTION ( "Healer::casting test" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );

        enemy->takeDamage(30);
        REQUIRE( enemy->getHitPoints() == 120 );
        healer->cast(enemy);
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( healer->getMana() == 70 );

        healer->changeSpell(fireBall);
        healer->cast(enemy);
        REQUIRE( enemy->getHitPoints() == 135 );
        REQUIRE( healer->getMana() == 40 );

        healer->changeSpell(inferno);
        try {
            healer->cast(enemy);
        } catch ( OutOfManaException obj ) {
            REQUIRE(enemy->getHitPoints() == 135);
            REQUIRE(healer->getMana() == 40);
        }
    }
}