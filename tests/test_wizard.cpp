//
// Created by denysvysochanskyi on 18.04.18.
//

#include "catch.hpp"
#include "../spellcaster/Wizard.h"
#include "../unit/Soldier.h"

TEST_CASE( "Test Wizard class" ) {
    Wizard* wizard = new Wizard("Wizard", 100, 10, 100);

    REQUIRE( wizard->getHitPoints() == 100 );
    REQUIRE( wizard->getHitPointsLimit() == 100 );
    REQUIRE( wizard->getTitle() == "Wizard" );
    REQUIRE( wizard->getDamage() == 10 );
    REQUIRE( wizard->getIsUndead() == false );
    REQUIRE( wizard->getIsTurnable() == true );
    REQUIRE( wizard->getIsWolf() == false );
    REQUIRE( wizard->getMana() == 100 );
    REQUIRE( wizard->getManaLimit() == 100 );

    SECTION( "Wizard::takeDamage tests" ) {
        int damage = 10;
        int iterations = wizard->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            wizard->takeDamage(damage);
            int expectedHP = wizard->getHitPointsLimit() - damage * i;
            REQUIRE( wizard->getHitPoints() == expectedHP );
        }

        try {
            wizard->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( wizard->getHitPoints() == 0 );
        }
    }

    SECTION( "Wizard::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = wizard->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            wizard->takeMagicDamage(damage);
            int expectedHP = wizard->getHitPointsLimit() - damage * i;
            REQUIRE( wizard->getHitPoints() == expectedHP );
        }

        try {
            wizard->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( wizard->getHitPoints() == 0 );
        }
    }

    SECTION( "Wizard::addHitpoits tests" ) {
        wizard->takeDamage(50);
        REQUIRE( wizard->getHitPoints() == 50 );

        wizard->addHitPoints(40);
        REQUIRE( wizard->getHitPoints() == 90 );

        wizard->addHitPoints(10);
        REQUIRE( wizard->getHitPoints() == 100 );

        wizard->addHitPoints(10);
        REQUIRE( wizard->getHitPoints() == 100 );

        wizard->takeDamage(100);
        REQUIRE( wizard->getHitPoints() == 0 );

        try {
            wizard->addHitPoints(40);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE(wizard->getHitPoints() == 0);
        }
    }

    SECTION( "Wizard::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );

        wizard->attack(enemy);

        REQUIRE( wizard->getHitPoints() == 90 );
        REQUIRE( enemy->getHitPoints() == 140 );

        enemy->attack(wizard);

        REQUIRE( wizard->getHitPoints() == 70 );
        REQUIRE( enemy->getHitPoints() == 135 );

        enemy->takeDamage(130);
        REQUIRE( enemy->getHitPoints() == 5 );

        try {
            wizard->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( wizard->getHitPoints() == 70 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            wizard->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( wizard->getHitPoints() == 70 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }
    }

    SECTION ( "Wizard::turn test" ) {
        Soldier* soldier = new Soldier("Enemy", 150, 20);

        REQUIRE( soldier->getHitPoints() == 150 );
        REQUIRE( soldier->getHitPointsLimit() == 150 );
        REQUIRE( soldier->getTitle() == "Enemy" );
        REQUIRE( soldier->getDamage() == 20 );
        REQUIRE( soldier->getIsUndead() == false );
        REQUIRE( soldier->getIsTurnable() == true );
        REQUIRE( soldier->getIsWolf() == false );

        try {
            wizard->turnEnemy(soldier);
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
            wizard->turnMyself();
        } catch( NotAllowedToTurn obj) {
            REQUIRE( wizard->getHitPoints() == 100 );
            REQUIRE( wizard->getHitPointsLimit() == 100 );
            REQUIRE( wizard->getTitle() == "Wizard" );
            REQUIRE( wizard->getDamage() == 10 );
            REQUIRE( wizard->getIsUndead() == false );
            REQUIRE( wizard->getIsTurnable() == true );
            REQUIRE( wizard->getIsWolf() == false );
            REQUIRE( wizard->getMana() == 100 );
            REQUIRE( wizard->getManaLimit() == 100 );
        }
    }

    SECTION ( "Wizard::add spend mana test" ) {
        wizard->addMana(20);
        REQUIRE( wizard->getMana() == 100 );

        wizard->spendMana(40);
        REQUIRE( wizard->getMana() == 60 );

        wizard->addMana(20);
        REQUIRE( wizard->getMana() == 80 );

        try {
            wizard->spendMana(90);
        } catch ( OutOfManaException obj ) {
            REQUIRE( wizard->getMana() == 80 );
        }

        wizard->addMana(30);
        REQUIRE( wizard->getMana() == 100 );
    }

    SECTION ( "Wizard::casting test" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );
        
        wizard->cast(enemy);
        REQUIRE( enemy->getHitPoints() == 120 );
        REQUIRE( wizard->getMana() == 70 );

        wizard->changeSpell(heal);
        wizard->cast(enemy);
        REQUIRE( enemy->getHitPoints() == 135 );
        REQUIRE( wizard->getMana() == 40 );

        wizard->changeSpell(inferno);
        try {
            wizard->cast(enemy);
        } catch ( OutOfManaException obj ) {
            REQUIRE(enemy->getHitPoints() == 135);
            REQUIRE(wizard->getMana() == 40);
        }
    }
}