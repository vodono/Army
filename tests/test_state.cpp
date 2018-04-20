//
// Created by denysvysochanskyi on 22.03.18.
//

#include "catch.hpp"
#include "../state/State.h"

TEST_CASE( "Test State class" ) {
    State* state = new State("State", 150, 20);

    REQUIRE( state->getTitle() == "State" );
    REQUIRE( state->getHitPoints() == 150 );
    REQUIRE( state->getHitPointsLimit() == 150 );
    REQUIRE( state->getDamage() == 20 );
}
