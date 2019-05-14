/** @file Cell.h
 * Defines and implements an individual cell of a grid.
 */
#ifndef _CELL_H
#define _CELL_H

#include <iostream>

// Possible states the cell can have
// UNVISITED: the cell is in an unknown state
// OCCUPIED: the cell is occupied
// UNOCCUPIED: the cell is unoccupied
// NONE: there is no cell (good for non-existant neighbors of outer edge cells)
// START: the cell represents the starting point
// END: the cell represents the ending point
namespace cell
{
    enum class State { UNVISITED, OCCUPIED, UNOCCUPIED, NONE, START, END };
}

class Cell
{
public:
    // Constructor
    Cell(const cell::State s = cell::State::UNVISITED,
         const int x = 0, const int y = 0) :
        state(s), xPosition(x), yPosition(x) {}

	// Copy constructor
	Cell(const Cell &c);

    // Accessors
    /** Returns the x-coordinate of the cell
    @return x-coordinate of the cell */
    int getXPosition() const { return xPosition; }

    /** Returns the y-coordinate of the cell
    @return y-coordinate of the cell */
    int getYPosition() const { return yPosition; }

    /** Returns the current state of the cell
    @return the state of the cell */
    cell::State getState() const { return state; }

    // Check state of cell
    /** Checks if the state of the cell is END
    @return true if state of the cell is END, false if not */
    bool isEnd() const { return state == cell::State::END; }

    /** Checks if the state of the cell is NONE
    @return true if state of the cell is NONE, false if not */
    bool isNone() const { return state == cell::State::NONE; }

    /** Checks if the cell is OCCUPIED or NONE
    @return true if state of the cell is OCCUPIED or NONE, false if not */
    bool isOccupied() const
        { return state == cell::State::OCCUPIED || state == cell::State::NONE; }

    /** Checks if the state of the cell is START
    @return true if state of the cell is START, false if not */
    bool isStart() const { return state == cell::State::START; }

    /** Checks if the state of the cell is not OCCUPIED
    @return true if state of the cell is not OCCUPIED, false if not */
    bool isUnoccupied() const { return state != cell::State::OCCUPIED; }

    /** Checks if the state of the cell is UNVISITED
    @return true if state of the cell is UNVISITED, false if not */
    bool isUnvisited() const { return state == cell::State::UNVISITED; }

    // Mutators
    /** Sets the x- and y-coordinates (position) of the cell
    @post The x- and y-coordinates (position) of the cell will be updated
    @param x The x-coordinate of the cell
    @param y The y-coordinate of the cell */
    void setPosition(const int x, const int y) { xPosition = x; yPosition = y; }

    /** Sets the state of the cell
    @post The x- and y-coordinates (position) of the cell will be updated
    @param s The state of the cell */
    void setState(const cell::State s) { state = s; }

    // Overloaded operators
    /** Overloaded = operator to allow assignment of cells
    @param right Reference to the right hand side of the = operator */
    void operator=(const Cell &right);

    /** Overloaded << operator to allow easy printing of Cell objects
    @param strm Reference to the ostream object
    @param obj Reference to the Cell object that's being printed
    @return The  ostream object (strm) */
    friend std::ostream &operator<<(std::ostream &strm, const Cell &obj);

private:
    int xPosition;      // x-coordinate of the cell
    int yPosition;      // y-coordinate of the cell
    cell::State state;  // state of the cell
};

#endif // _CELL_H
