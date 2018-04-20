//
// Created by denysvysochanskyi on 27.03.18.
//

#include "catch.hpp"
#include "../unit/Soldier.h"

TEST_CASE( "Test Soldier class" ) {
    Soldier* soldier = new Soldier("Soldier", 150, 20);

    REQUIRE( soldier->getHitPoints() == 150 );
    REQUIRE( soldier->getHitPointsLimit() == 150 );
    REQUIRE( soldier->getTitle() == "Soldier" );
    REQUIRE( soldier->getDamage() == 20 );
    REQUIRE( soldier->getIsUndead() == false );
    REQUIRE( soldier->getIsTurnable() == true );

    SECTION( "Soldier::takeDamage tests" ) {
        int damage = 10;
        int iterations = soldier->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            soldier->takeDamage(damage);
            int expectedHP = soldier->getHitPointsLimit() - damage * i;
            REQUIRE( soldier->getHitPoints() == expectedHP );
        }

        try {
            soldier->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( soldier->getHitPoints() == 0 );
        }
    }

    SECTION( "Soldier::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = soldier->getHitPoints() / damage;

        for ( int i = 1; i < iterations; i++ ) {
            soldier->takeMagicDamage(damage);
            int expectedHP = soldier->getHitPointsLimit() - damage * i;
            REQUIRE( soldier->getHitPoints() == expectedHP );
        }

        try {
            soldier->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( soldier->getHitPoints() == 0 );
        }
    }

    SECTION( "Soldier::addHitpoits tests" ) {
        soldier->takeDamage(50);
        REQUIRE( soldier->getHitPoints() == 100 );

        soldier->addHitPoints(40);
        REQUIRE( soldier->getHitPoints() == 140 );

        soldier->addHitPoints(10);
        REQUIRE( soldier->getHitPoints() == 150 );

        soldier->addHitPoints(10);
        REQUIRE( soldier->getHitPoints() == 150 );

        soldier->takeDamage(150);
        REQUIRE( soldier->getHitPoints() == 0 );

        try {
            soldier->addHitPoints(40);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE(soldier->getHitPoints() == 0);
        }
    }

    SECTION( "Soldier::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );

        soldier->attack(enemy);

        REQUIRE( soldier->getHitPoints() == 140 );
        REQUIRE( enemy->getHitPoints() == 130 );

        soldier->attack(enemy);
        soldier->attack(enemy);
        soldier->attack(enemy);

        REQUIRE( soldier->getHitPoints() == 110 );
        REQUIRE( enemy->getHitPoints() == 70 );

        enemy->takeDamage(60);
        REQUIRE( enemy->getHitPoints() == 10 );

        try {
            soldier->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( soldier->getHitPoints() == 110 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            soldier->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( soldier->getHitPoints() == 110 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

    }
}