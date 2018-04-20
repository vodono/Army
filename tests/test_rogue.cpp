//
// Created by denysvysochanskyi on 27.03.18.
//

#include "catch.hpp"
#include "../unit/Rogue.h"
#include "../unit/Soldier.h"

TEST_CASE( "Test Rogue class" ) {
    Rogue* rogue = new Rogue("Rogue", 100, 15);

    REQUIRE( rogue->getHitPoints() == 100 );
    REQUIRE( rogue->getHitPointsLimit() == 100 );
    REQUIRE( rogue->getTitle() == "Rogue" );
    REQUIRE( rogue->getDamage() == 15 );
    REQUIRE( rogue->getIsUndead() == false );
    REQUIRE( rogue->getIsTurnable() == true );


    SECTION( "Rogue::takeDamage tests" ) {
        int damage = 10;
        int iterations = rogue->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            rogue->takeDamage(damage);
            int expectedHP = rogue->getHitPointsLimit() - damage * i;
            REQUIRE( rogue->getHitPoints() == expectedHP );
        }

        try {
            rogue->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoints() == 0 );
        }
    }

    SECTION( "Rogue::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = rogue->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            rogue->takeMagicDamage(damage);
            int expectedHP = rogue->getHitPointsLimit() - damage * i;
            REQUIRE( rogue->getHitPoints() == expectedHP );
        }

        try {
            rogue->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoints() == 0 );
        }
    }

    SECTION( "Rogue::addHitpoits tests" ) {
        rogue->takeDamage(50);
        REQUIRE( rogue->getHitPoints() == 50 );

        rogue->addHitPoints(40);
        REQUIRE( rogue->getHitPoints() == 90 );

        rogue->addHitPoints(10);
        REQUIRE( rogue->getHitPoints() == 100 );

        rogue->addHitPoints(10);
        REQUIRE( rogue->getHitPoints() == 100 );

        rogue->takeDamage(100);
        REQUIRE( rogue->getHitPoints() == 0 );

        try {
            rogue->addHitPoints(40);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE(rogue->getHitPoints() == 0);
        }
    }

    SECTION( "Soldier::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );

        rogue->attack(enemy);

        REQUIRE( rogue->getHitPoints() == 100 );
        REQUIRE( enemy->getHitPoints() == 135 );

        rogue->attack(enemy);
        rogue->attack(enemy);
        rogue->attack(enemy);

        REQUIRE( rogue->getHitPoints() == 100 );
        REQUIRE( enemy->getHitPoints() == 90 );

        enemy->takeDamage(90);
        REQUIRE( enemy->getHitPoints() == 0 );

        try {
            rogue->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoints() == 100 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            enemy->attack(rogue);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoints() == 100 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

    }

}