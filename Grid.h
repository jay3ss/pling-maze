/** @file Grid.h
 * Defines and implements grid of cell objects.
 */
#ifndef _GRID_H
#define _GRID_H

#include <iostream>
#include <vector>
#include "Cell.h"

class Grid
{
public:
    // Constructor
    Grid(int c = 1, int r = 1) : numCols(c), numRows(r)
        { init(); }

    // Destructor
    ~Grid() {}

    // Accessors
    /** Returns the number of columns of the grid
    @return The integer number of columns in the grid */
    int getNumCols() const { return numCols; }

    /** Returns the number of rows of the grid
    @return The integer number of rows in the grid */
    int getNumRows() const { return numRows; }

    /** Returns a cell at a given position in the grid. If the given position
        is out the bounds of the grid (either: x < 0, x > numCols or y < 0,
        y > numRows) then a cell with the state of NONE is returned
    @param x-coordinate of the cell
    @param y-coordinate of the cell
    @return The cell at the given coordinates. If the cell is out of bounds,
        then a cell with the state of NONE is returned (there are no cells
        that are out of bounds) and the passed in coordinates. */
    Cell getCellAt(int x, int y);

    /** Returns all of the cells in the grid as a 2-dimensional vector
    @return A 2-dimensional vector containing the cells of the grid */
    std::vector<std::vector<Cell>> vector() const { return cells; }

    /** Checks if a cell is out of the bounds of the grid
    @param x The x-coordinate of the cell in question
    @param y The y-coordinate of the cell in question
    @return true if the cell is out of the bounds of the grid, false
        otherwise */
    bool isOutOfBounds(int x, int y);

    // Mutators
    /** Resizes the grid to the desired number of columns and rows
    @param c The desired number of columns
    @param r The desired number of rows
    @post The grid will be a c x r grid and all cells within the grid will have
        the state OF UNVISITED */
    void resize(int c, int r);

    /** Replaces the current cell in the grid with the passed in cell
    @pre The current cell is determined by the position of the passed in cell,
        c. No bounds checking is performed so the passed in cell should be
        within the bounds of the grid.
    @param c The cell to replace the cell in the grid
    @post The current cell in the grid will be replaced with the passed in
        cell, c */
    void setCell(Cell c);

    // Overloaded operators
    /** Overloaded << operator to allow easy printing of Grid objects
    @param strm Reference to the ostream object
    @param obj Reference to the Grid object that's being printed
    @return The  ostream object (strm) */
    friend std::ostream &operator<<(std::ostream &strm, const Grid &obj);
private:
    int numCols;    // Number of columns in the grid
    int numRows;    // Number of rows in the grid

    std::vector<std::vector<Cell>> cells;   // 2D vector of cells, defines grid

    /** Initializes the grid, called in the constructor
    @post The grid is resized to be a numCols x numRows grid and all cells
        within the grid will have the state OF UNVISITED */
    void init();
};

#endif // _GRID_H
