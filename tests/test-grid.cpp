// Tests for the Grid class
#include <string>
#include <vector>
#include <catch2/catch.hpp>
#include "pling/Cell.h"
#include "pling/Grid.h"

std::string sngFile = "[single-file]";

TEST_CASE("Grid default number of columns and rows should be 1", sngFile)
{
    Grid g;

    REQUIRE(g.getNumCols() == 1);
    REQUIRE(g.getNumRows() == 1);
}

TEST_CASE("Should be able to resize the grid", sngFile)
{
    Grid g;
    int newNumCols = 3;
    int newNumRows = 5;
    g.resize(newNumCols, newNumRows);

    REQUIRE(g.getNumCols() == newNumCols);
    REQUIRE(g.getNumRows() == newNumRows);
}

TEST_CASE("Should be able to instantiate the grid to a predetermined size", sngFile)
{
    int numCols = 13;
    int numRows = 75;
    Grid g(numCols, numRows);

    REQUIRE(g.getNumCols() == numCols);
    REQUIRE(g.getNumRows() == numRows);
}

TEST_CASE("Should be able to get an arbitrary cell from the grid", sngFile)
{
    int numCols = 42;
    int numRows = 47;
    Grid g(numCols, numRows);

    int xPos = 13;
    int yPos = 37;
    Cell c = g.getCellAt(xPos, yPos);

    REQUIRE(c.getState() == cell::State::UNVISITED);
    REQUIRE(c.getXPosition() == xPos);
    REQUIRE(c.getYPosition() == yPos);
}

TEST_CASE("Grid should be able to test if a cell is out of bounds", sngFile)
{
    int numCols = 5;
    int numRows = 5;
    Grid g(numCols, numRows);

    REQUIRE(g.isOutOfBounds(0, -1));

    // Cell c = g.getCellAt(0, -1);
    // This is the desired API as well
    // REQUIRE(g.isOutOfBounds(c));
}

TEST_CASE("Getting an out of bounds cell should have a state of NONE", sngFile)
{
    // Get a cell out of bounds on each side of the grid
    int numCols = 5;
    int numRows = 5;
    Grid g(numCols, numRows);

    // North
    Cell c = g.getCellAt(0, -1);
    REQUIRE(c.getState()== cell::State::NONE);

    // South
    c = g.getCellAt(0, numCols + 1);
    REQUIRE(c.getState() == cell::State::NONE);

    // East
    c = g.getCellAt(0, numRows + 1);
    REQUIRE(c.getState() == cell::State::NONE);

    // West
    c = g.getCellAt(-1, 0);
    REQUIRE(c.getState() == cell::State::NONE);
}

TEST_CASE("Grid should be able tot change the state of a cell", sngFile)
{
    int numCols = 5;
    int numRows = 5;
    Grid g(numCols, numRows);

    int xPos = 3;
    int yPos = 3;
    Cell c(cell::State::OCCUPIED, xPos, yPos);
    g.setCell(c);

    Cell newCell = g.getCellAt(xPos, yPos);

    REQUIRE(newCell.getState() == cell::State::OCCUPIED);
    REQUIRE(newCell.getXPosition() == xPos);
    REQUIRE(newCell.getYPosition() == yPos);
}

TEST_CASE("Grid should return a 2D vector of Cell objects", sngFile)
{
    int numCols = 3;
    int numRows = 5;
    Grid g(numCols, numRows);

    std::vector<std::vector<Cell>> gVect = g.vector();

    REQUIRE(gVect.size() == numCols);
    REQUIRE(gVect[0].size() == numRows);
}
