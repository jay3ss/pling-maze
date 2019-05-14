/** @file Maze.h
 * Defines and implements a maze.
 */
#ifndef _MAZE_H
#define _MAZE_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>
#include <stack>
#include <vector>
#include "pling/Cell.h"
#include "pling/Grid.h"

// Defines the direction within the maze. The maze starts at (0, 0) in the top
// left and increases to the right and down.
// NORTH: up
// EAST: right
// SOUTH: down
// WEST: left
namespace maze
{
    enum class Direction { NORTH, EAST, SOUTH, WEST };
}

class Maze
{
public:
    /** Constructor
    @post The x- and y-coordinates (position) of the cell will be updated
    @param c The desired number of columns
    @param r The desired number of rows
    @param randStart Determines if the starting point of the maze will be
        determined randomly. If true, the starting point is determined randomly
        otherwise, the user must set it manually */
    Maze(int c = 1, int r = 1, bool randStart = true);

    // Destructor
    ~Maze() {}

    // Accessors
    /** Returns the grid object of the maze
    @return The maze's grid */
    Grid getGrid() { return grid; }

    /** Returns the starting cell
    @return The starting cell */
    Cell getStart() { return grid.getCellAt(start[0], start[1]); }

    /** Returns a cell at a given position in the grid. If the given position
        is out the bounds of the grid (either: x < 0, x > numCols or y < 0,
        y > numRows) then a cell with the state of NONE is returned
    @param x-coordinate of the cell
    @param y-coordinate of the cell
    @return The cell at the given coordinates. If the cell is out of bounds,
        then a cell with the state of NONE is returned (there are no cells
        that are out of bounds) and the passed in coordinates. */
    Cell getCellAt(int x, int y) { return grid.getCellAt(x, y); }

    /** Returns the value used to seed the random number generator
    @return The value used to seed the random number generator */
    const unsigned getSeed() const { return SEED; }

    // Maze generation-related functions
    /** A maze generation algorithm that utilizes stacks is the randomized
        depth-first search algorithm
    @pre A start point needs to be set, either through the constructor (using
        the random start option), or manually.
    @post Every cell's state in the grid will be changed, either to occupied or
        unoccupied. */
    void generate();

    /** Checks if a cell has any unvisited neighbors
    @param c Cell object to see if it has any neighbors
    @return true if the cell has any unvisited neighbors, false otherwise */
    bool hasUnvisitedNeighbors(Cell c);

    /** Returns a random state
    @return A random state, either: OCCUPIED or UNOCCUPIED */
    cell::State getRandomState() const;

    // Wall-/cell-related functions
    /** Checks if a cell is a wall
    @param c The cell to check
    @return true if the cell is a wall, false otherwise */
    bool isWall(Cell c);

    /** Checks if a cell is an outer wall
    @param x x-coordinate of the cell
    @param y y-coordinate of the cell
    @return true if the cell is an outer wall, false otherwise */
    bool isOuterWall(int x, int y);

    /** Checks if a cell is a north wall
    @param y y-coordinate of the cell
    @return true if the cell is a north wall, false otherwise */
    bool isNorthWall(int y);

    /** Checks if a cell is a south wall
    @param y y-coordinate of the cell
    @return true if the cell is a south wall, false otherwise */
    bool isSouthWall(int y);

    /** Checks if a cell is an east wall
    @param x x-coordinate of the cell
    @return true if the cell is an east wall, false otherwise */
    bool isEastWall(int x);

    /** Checks if a cell is a west wall
    @param x x-coordinate of the cell
    @return true if the cell is a west wall, false otherwise */
    bool isWestWall(int x);

    /** Checks if a cell is the starting point
    @param x x-coordinate of the cell
    @param y y-coordinate of the cell
    @return true if the cell is the starting point, false otherwise */
    bool isStart(int x, int y);

    // Mutators
    /** Defines the starting point
    @param x x-coordinate of the starting point
    @param x x-coordinate of the starting point
    @post The cell located at (x, y) will be set to the starting point */
    void setStart(const int x, const int y);

    /** Returns a random neighbor to the passed in cell, if possible
    @param c The cell to find the neighbor of
    @return The random neighboring cell, if possible. If not possible a cell
        with the state NONE is returned */
    Cell getRandomNeighbor(Cell c);

    // Overloaded operators
    /** Overloaded << operator to allow easy printing of Maze objects
    @param strm Reference to the ostream object
    @param obj Reference to the Maze object that's being printed
    @return The  ostream object (strm) */
    friend std::ostream &operator<<(std::ostream &strm, const Maze &obj);
private:
    std::stack<Cell> stack;     // Stack for the maze generation algorithm
    Grid grid;                  // Grid for the maze
    int start[2];               // Starting point

    /** Initialize grid with outer cells as occupied (walls)
    @post The cells along north, south, east, and west of the grid will be set
        to occupied (a wall) */
    void initGrid();

    // Random number generation
    /** Returns a random number within a specified range
    @param min The minimum number of the range
    @param min The maximum number of the range
    @return A random number between min and max */
    int generateRandomNumber(int min, int max);

    /** Seeds the random number generator
    @post The random number will be seeded */
    void seedRandGen();

    /** Sets the starting point to a random location within the maze that ins't
        a wall
    @post The starting point will be set */
    void randomStart();

    // Seed for the random number generator
    const unsigned SEED = std::time(0);
};

#endif // _MAZE_H
