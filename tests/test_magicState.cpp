//
// Created by denysvysochanskyi on 27.03.18.
//

#include "catch.hpp"
#include "../state/MagicState.h"

TEST_CASE( "test MagicState class" ) {
    MagicState* state = new MagicState(150);

    REQUIRE( state->getMana() == 150 );
    REQUIRE( state->getManaLimit() == 150 );

    SECTION( "MagicState::spendMana tests" ) {
        int cost = 10;
        int iterations = state->getMana() / cost;

        for ( int i = 1; i < iterations; i++ ) {
            state->spendMana(cost);
            int expectedMana = state->getManaLimit() - i * cost;
            REQUIRE( state->getMana() == expectedMana );
        }

        try {
            state->spendMana(cost);
        } catch ( OutOfManaException obj ) {
            REQUIRE( state->getMana() == 0 );
        }
    }

    SECTION( "MagicState::addMana tests" ) {
        state->spendMana(50);
        REQUIRE( state->getMana() == 100 );

        state->addMana(40);
        REQUIRE( state->getMana() == 140 );

        state->addMana(10);
        REQUIRE( state->getMana() == 150 );

        state->addMana(10);
        REQUIRE( state->getMana() == 150 );
    }
}