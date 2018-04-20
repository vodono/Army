//
// Created by denysvysochanskyi on 27.03.18.
//

#include "catch.hpp"
#include "../unit/Berserker.h"
#include "../unit/Soldier.h"

TEST_CASE( "Test Berserker class" ) {
    Berserker* berserker = new Berserker("Berserker", 150, 30);

    REQUIRE( berserker->getHitPoints() == 150 );
    REQUIRE( berserker->getHitPointsLimit() == 150 );
    REQUIRE( berserker->getTitle() == "Berserker" );
    REQUIRE( berserker->getDamage() == 30 );
    REQUIRE( berserker->getIsUndead() == false );
    REQUIRE( berserker->getIsTurnable() == true );


    SECTION( "Berserker::takeDamage tests" ) {
        int damage = 10;
        int iterations = berserker->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            berserker->takeDamage(damage);
            int expectedHP = berserker->getHitPointsLimit() - damage * i;
            REQUIRE( berserker->getHitPoints() == expectedHP );
        }

        try {
            berserker->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( berserker->getHitPoints() == 0 );
        }
    }

    SECTION( "Berserker::takeMagicDamage tests" ) {
        int damage = 100;

        berserker->takeMagicDamage(damage);
        REQUIRE( berserker->getHitPoints() == berserker->getHitPointsLimit() );

        try {
            berserker->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( berserker->getHitPoints() == berserker->getHitPointsLimit() );
        }
    }

    SECTION( "Berserker::addHitpoits tests" ) {
        berserker->takeDamage(50);
        REQUIRE( berserker->getHitPoints() == 100 );

        berserker->addHitPoints(40);
        REQUIRE( berserker->getHitPoints() == 140 );

        berserker->addHitPoints(10);
        REQUIRE( berserker->getHitPoints() == 150 );

        berserker->addHitPoints(10);
        REQUIRE( berserker->getHitPoints() == 150 );

        berserker->takeDamage(150);
        REQUIRE( berserker->getHitPoints() == 0 );

        try {
            berserker->addHitPoints(40);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE(berserker->getHitPoints() == 0);
        }
    }

    SECTION( "Berserker::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 150, 20);

        REQUIRE( enemy->getHitPoints() == 150 );
        REQUIRE( enemy->getHitPointsLimit() == 150 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );

        berserker->attack(enemy);

        REQUIRE( berserker->getHitPoints() == 140 );
        REQUIRE( enemy->getHitPoints() == 120 );

        berserker->attack(enemy);
        berserker->attack(enemy);
        berserker->attack(enemy);

        REQUIRE( berserker->getHitPoints() == 110 );
        REQUIRE( enemy->getHitPoints() == 30 );

        enemy->takeDamage(30);
        REQUIRE( enemy->getHitPoints() == 0 );

        try {
            berserker->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( berserker->getHitPoints() == 110 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            enemy->attack(berserker);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( berserker->getHitPoints() == 110 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

    }

}