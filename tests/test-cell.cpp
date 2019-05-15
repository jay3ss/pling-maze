// Tests for the Cell class
#include <catch2/catch.hpp>
#include "pling/Cell.h"

TEST_CASE("Cell default state should be UNVISITED", "[single-file]")
{
    Cell c;

    REQUIRE(c.getState() == cell::State::UNVISITED);
}

TEST_CASE("Can set the cell state", "[single-file]")
{
    Cell c;
    c.setState(cell::State::END);

    REQUIRE(c.getState() == cell::State::END);

    c.setState(cell::State::OCCUPIED);
    REQUIRE(c.getState() == cell::State::OCCUPIED);

    c.setState(cell::State::NONE);
    REQUIRE(c.getState() == cell::State::NONE);

    c.setState(cell::State::START);
    REQUIRE(c.getState() == cell::State::START);

    c.setState(cell::State::UNOCCUPIED);
    REQUIRE(c.getState() == cell::State::UNOCCUPIED);

    c.setState(cell::State::UNVISITED);
    REQUIRE(c.getState() == cell::State::UNVISITED);
}

TEST_CASE("Cell default position should be (0, 0)", "[single-file]")
{
    Cell c;
    REQUIRE(c.getXPosition() == 0);
    REQUIRE(c.getXPosition() == 0);
}

TEST_CASE("Can set the cell's position to (1, 37)", "[single-file]")
{
    Cell c;
    c.setPosition(1, 37);

    REQUIRE(c.getXPosition() == 1);
    REQUIRE(c.getYPosition() == 37);
}
