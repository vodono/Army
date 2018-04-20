//
// Created by denysvysochanskyi on 27.03.18.
//

#include "catch.hpp"
#include "../unit/Werewolf.h"
#include "../unit/Soldier.h"

TEST_CASE( "Test Werewolf class" ) {
    Werewolf* werewolf = new Werewolf("Werewolf", 100, 20);

    REQUIRE( werewolf->getHitPoints() == 100 );
    REQUIRE( werewolf->getHitPointsLimit() == 100 );
    REQUIRE( werewolf->getTitle() == "Werewolf" );
    REQUIRE( werewolf->getDamage() == 20 );
    REQUIRE( werewolf->getIsUndead() == false );
    REQUIRE( werewolf->getIsTurnable() == false );
    REQUIRE( werewolf->getIsWolf() == false );


    SECTION( "Werewolf::takeDamage tests" ) {
        int damage = 10;
        int iterations = werewolf->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            werewolf->takeDamage(damage);
            int expectedHP = werewolf->getHitPointsLimit() - damage * i;
            REQUIRE( werewolf->getHitPoints() == expectedHP );
        }

        REQUIRE( werewolf->getHitPoints() == 0 );

        try {
            werewolf->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::takeDamage as wolf tests" ) {
        werewolf->turnMyself();

        REQUIRE( werewolf->getHitPoints() == 120 );
        REQUIRE( werewolf->getHitPointsLimit() == 120 );
        REQUIRE( werewolf->getTitle() == "Werewolf" );
        REQUIRE( werewolf->getDamage() == 24 );
        REQUIRE( werewolf->getIsUndead() == false );
        REQUIRE( werewolf->getIsTurnable() == false );
        REQUIRE( werewolf->getIsWolf() == true );

        int damage = 10;
        int iterations = werewolf->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            werewolf->takeDamage(damage);
            int expectedHP = werewolf->getHitPointsLimit() - damage * i;
            REQUIRE( werewolf->getHitPoints() == expectedHP );
        }

        REQUIRE( werewolf->getHitPoints() == 0 );

        try {
            werewolf->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = werewolf->getHitPoints() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            werewolf->takeMagicDamage(damage);
            int expectedHP = werewolf->getHitPointsLimit() - damage * i;
            REQUIRE( werewolf->getHitPoints() == expectedHP );
        }

        REQUIRE( werewolf->getHitPoints() == 0 );

        try {
            werewolf->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::takeMagicDamage as wolf tests" ) {
        werewolf->turnMyself();
        int damage = 10;
        int iterations = werewolf->getHitPoints() / (int)(damage * 1.2);

        for ( int i = 1; i <= iterations; i++ ) {
            werewolf->takeMagicDamage(damage);
            int expectedHP = werewolf->getHitPointsLimit() - (int)(damage * 1.2) * i;
            REQUIRE( werewolf->getHitPoints() == expectedHP );
        }

        REQUIRE( werewolf->getHitPoints() == 0 );

        try {
            werewolf->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::addHitpoits tests" ) {
        werewolf->takeDamage(50);
        REQUIRE( werewolf->getHitPoints() == werewolf->getHitPointsLimit() - 50 );

        werewolf->addHitPoints(40);
        REQUIRE( werewolf->getHitPoints() == werewolf->getHitPointsLimit() - 10 );

        werewolf->addHitPoints(10);
        REQUIRE( werewolf->getHitPoints() == werewolf->getHitPointsLimit() );

        werewolf->addHitPoints(10);
        REQUIRE( werewolf->getHitPoints() == werewolf->getHitPointsLimit() );

        werewolf->takeDamage(werewolf->getHitPointsLimit());
        REQUIRE( werewolf->getHitPoints() == 0 );

        try {
            werewolf->addHitPoints(40);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE(werewolf->getHitPoints() == 0);
        }
    }

    SECTION( "Werewolf::addHitpoits as wolf tests" ) {
        werewolf->turnMyself();

        werewolf->takeDamage(50);
        REQUIRE( werewolf->getHitPoints() == werewolf->getHitPointsLimit() - 50 );

        werewolf->addHitPoints(40);
        REQUIRE( werewolf->getHitPoints() == werewolf->getHitPointsLimit() - 10 );

        werewolf->turnMyself();

        REQUIRE( werewolf->getHitPoints() == (int) (110 / WOLF_RATE) );

        werewolf->turnMyself();

        werewolf->addHitPoints(10);
        REQUIRE( werewolf->getHitPoints() == (int) (((int)(110 / WOLF_RATE)) * WOLF_RATE + 10) );

        werewolf->addHitPoints(10);
        REQUIRE( werewolf->getHitPoints() == werewolf->getHitPointsLimit() );

        werewolf->takeDamage(werewolf->getHitPointsLimit());
        REQUIRE( werewolf->getHitPoints() == 0 );

        try {
            werewolf->addHitPoints(40);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE(werewolf->getHitPoints() == 0);
        }
    }

    SECTION( "Werewolf::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy", 100, 20);

        REQUIRE( enemy->getHitPoints() == 100 );
        REQUIRE( enemy->getHitPointsLimit() == 100 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );

        werewolf->attack(enemy);

        REQUIRE( werewolf->getHitPoints() == 90 );
        REQUIRE( enemy->getHitPoints() == 80 );

        werewolf->attack(enemy);
        werewolf->attack(enemy);
        werewolf->attack(enemy);

        REQUIRE( werewolf->getHitPoints() == 60 );
        REQUIRE( enemy->getHitPoints() == 20 );

        enemy->takeDamage(20);
        REQUIRE( enemy->getHitPoints() == 0 );

        try {
            werewolf->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == 60 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            enemy->attack(werewolf);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == 60 );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

    }

    SECTION( "Werewolf::attack as wolf tests" ) {
        Soldier* enemy = new Soldier("Enemy", 100, 20);

        REQUIRE( enemy->getHitPoints() == 100 );
        REQUIRE( enemy->getHitPointsLimit() == 100 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );

        werewolf->turnMyself();

        werewolf->attack(enemy);

        REQUIRE( werewolf->getHitPoints() == 110 );
        REQUIRE( enemy->getHitPoints() == 76 );

        werewolf->turnMyself();

        REQUIRE( werewolf->getHitPoints() == (int) (110 / WOLF_RATE) );
        REQUIRE( enemy->getHitPoints() == 76 );

        enemy->takeDamage(76);
        REQUIRE( enemy->getHitPoints() == 0 );

        try {
            werewolf->attack(enemy);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == (int) (110 / WOLF_RATE) );
            REQUIRE( enemy->getHitPoints() == 0 );
        }

        try {
            enemy->attack(werewolf);
        } catch( OutOfHitPointsException obj ) {
            REQUIRE( werewolf->getHitPoints() == (int) (110 / WOLF_RATE) );
            REQUIRE( enemy->getHitPoints() == 0 );
        }
    }

    SECTION( "Werewolf::turn enemy tests" ) {
        Soldier* enemy = new Soldier("Enemy", 100, 20);

        REQUIRE( enemy->getHitPoints() == 100 );
        REQUIRE( enemy->getHitPointsLimit() == 100 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == true );
        REQUIRE( enemy->getIsWolf() == false );

        werewolf->attack(enemy);
        werewolf->turnEnemy(enemy);

        REQUIRE( enemy->getHitPoints() == 80 );
        REQUIRE( enemy->getHitPointsLimit() == 100 );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getDamage() == 20 );
        REQUIRE( enemy->getIsUndead() == false );
        REQUIRE( enemy->getIsTurnable() == false );
        REQUIRE( enemy->getIsWolf() == false );

        enemy->attack(werewolf);
        REQUIRE( werewolf->getHitPoints() == 70 );
        REQUIRE( enemy->getHitPoints() == 70 );

        enemy->turnMyself();
        REQUIRE( werewolf->getHitPoints() == 70 );
        REQUIRE( enemy->getHitPoints() == (int) (70 * WOLF_RATE) );
    }
}
