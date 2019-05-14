/** @file Cell.cpp
 * Implements an individual cell of a grid.
 */
#include "pling/Cell.h"

// Copy constructor
Cell::Cell(const Cell &c)
{
	state = c.state;
	xPosition = c.xPosition;
	yPosition = c.yPosition;
}

// Overloaded ostream operator
std::ostream &operator<<(std::ostream &strm, const Cell &obj)
{
    switch (obj.state)
    {
    case cell::State::OCCUPIED:
        strm << "#";
        break;
    case cell::State::UNOCCUPIED:
        strm << " ";
        break;
    case cell::State::UNVISITED:
        strm << "?";
        break;
    case cell::State::START:
        strm << "*";
        break;
    case cell::State::END:
        strm << "x";
        break;
    default:
        strm << "";
        break;
    }

    return strm;
}

// Overloaded '=' operator
void Cell::operator=(const Cell &right)
{
    state = right.state;
	xPosition = right.xPosition;
	yPosition = right.yPosition;
}
