//
// Created by denysvysochanskyi on 27.03.18.
//

#include "catch.hpp"
#include "../unit/Vampire.h"
#include "../unit/Soldier.h"

TEST_CASE( "Test Vampire class" ) {
    Vampire* vampire = new Vampire("Vampire", 150, 20);

    REQUIRE( vampire->getHitPoints() == 150 );
    REQUIRE( vampire->getHitPointsLimit() == 150 );
    REQUIRE( vampire->getTitle() == "Vampire" );
    REQUIRE( vampire->getDamage() == 20 );
    REQUIRE( vampire->getIsUndead() == true );
    REQUIRE( vampire->getIsTurnable() == false );


    SECTION( "Vampire::takeDamage tests" ) {
        int damage = 10;
        int iterations = vampire->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            vampire->takeDamage(damage);
            int expectedHP = vampire->getHitPointsLimit() - damage * i;
            REQUIRE( vampire->getHitPoints() == expectedHP );
        }

        try {
            vampire->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }
    }

    SECTION( "Vampire::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = vampire->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            vampire->takeMagicDamage(damage);
            int expectedHP = vampire->getHitPointsLimit() - damage * i;
            REQUIRE( vampire->getHitPoints() == expectedHP );
        }

        try {
            vampire->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( vampire->getHitPoints() == 0 );
        }
    }

    SECTION( "Vampire::addHitpoits tests" ) {
        vampire->takeDamage(50);
        REQUIRE( vampire->getHitPoints() == vampire->getHitPointsLimit() - 50 );

        vampire->addHitPoints(40);
        REQUIRE( vampire->getHitPoints() == vampire->getHitPointsLimit() - 10 );

        vampire->addHitPoints(10);
        REQUIRE( vampire->getHitPoints() == vampire->getHitPointsLimit() );

        vampire->addHitPoints(10);
        REQUIRE( vampire->getHitPoints() == vampire->getHitPointsLimit() );

        vampire->takeDamage(vampire->getHitPointsLimit());
        REQUIRE( vampire->getHitPoints() == 0 );

        try {
            vampire->addHitPoints(40);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE(vampire->getHitPoints() == 0);
        }
    }

    SECTION( "Vampire::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );

        vampire->attack(enemy);

        REQUIRE( vampire->getHitPoints() == 140 );
        REQUIRE( enemy->getHitPoints() == 130 );

        vampire->attack(enemy);
        vampire->attack(enemy);
        vampire->attack(enemy);

        REQUIRE( vampire->getHitPoints() == 140 + (6 - 10) * 3 );
        REQUIRE( enemy->getHitPoints() == 70 );

        enemy->takeDamage(70);
        REQUIRE( enemy->getHitPoints() == 0 );

        try {
            vampire->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( vampire->getHitPoints() == 128 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            enemy->attack(vampire);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( vampire->getHitPoints() == 128 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

    }

    SECTION( "Vampire::turnEnemy test" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);
        Soldier* enemy2 = new Soldier("Enemy2", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );

        vampire->turnEnemy(enemy);
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == true );
        REQUIRE( enemy->getIsTurnable() == false );

        enemy->turnEnemy(enemy2);
        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == true );
        REQUIRE( enemy->getIsTurnable() == false );
    }
}