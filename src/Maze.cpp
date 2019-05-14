/** @file Maze.h
 * Implements a maze.
 */
#include "pling/Maze.h"

// Constructor
Maze::Maze(const int c, const int r, const bool randStart)
{
    grid = Grid(c, r);
    initGrid();
    seedRandGen();

    if (randStart)
    {
        randomStart();
    }
}

// A maze generation algorithm that utilizes stacks is the randomized depth-first search algorithm.
// Pseudocode
//
// The following is taken from Wikipedia:
//
//     1. Start with a grid that has no edges (all walls)
//     2. Make the initial cell the current cell
//     3. Push the current cell to the stack and mark it as visited
//     4. While the stack is not empty
//         a. If the current cell has unvisited neighbors
//             1. Choose one of these neighbors randomly
//             2. Remove the wall (add an edge) between the current cell and the chosen neighbor
//             3. Push the neighbor to the stack and mark it as visited
//             4. make the neighbor the current cell
//         b. Else
//             1. Pop a cell from the stack and make it the current cell (i.e., backtrack)
// Notes:
// - a visited cell is a cell whose state is not UNVISITED (not counting
//   START and END)
// - an occupied cell is a cell whose state is either OCCUPIED or NONE
void Maze::generate()
{
    // // Start at the starting point and set its state to UNOCCUPIED
    Cell startCell = getStart();
    // Mark the cell as visited & push it to the stack
    startCell.setState(cell::State::UNOCCUPIED);
	grid.setCell(startCell);
	stack.push(startCell);

    Cell topCell = stack.top();
    while (!stack.empty())
    {
        // Randomly get a neighbor to topCell
        Cell nextCell = getRandomNeighbor(topCell);

        if (!nextCell.isUnvisited())
        {
            // Backtrack
            stack.pop();
        }
        else
        {
            // Move ahead
            nextCell.setState(getRandomState());
			grid.setCell(nextCell);
			stack.push(nextCell);
        }

        if (!stack.empty())
        {
            topCell = stack.top();
        }
    }
}

// Checks if there are any unvisited neighboring cells. Returns true if there
// are any unvisited neighboring cells, false otherwise
bool Maze::hasUnvisitedNeighbors(const Cell &c)
{
    int xPos = c.getXPosition();
    int yPos = c.getYPosition();
    // Check the neighbors one-by-one
    // Check the neighbor to the north
    Cell neighbor = getCellAt(xPos, yPos + 1);

    if (neighbor.isUnvisited())
    {
        return true;
    }

    // Check the neighbor to the east
    neighbor = getCellAt(xPos + 1, yPos);

    if (neighbor.isUnvisited())
    {
        return true;
    }

    // Check the neighbor to the south
    neighbor = getCellAt(xPos, yPos - 1);

    if (neighbor.isUnvisited())
    {
        return true;
    }

    // Check the neighbor to the west
    neighbor = getCellAt(xPos - 1, yPos);

    if (neighbor.isUnvisited())
    {
        return true;
    }

    return false;
}

// Returns  random state, either: OCCUPIED or UNOCCUPIED
cell::State Maze::getRandomState() const
{

    std::vector<cell::State> states = {
        cell::State::OCCUPIED, cell::State::UNOCCUPIED
    };

    std::random_shuffle(states.begin(), states.end());

    return states[0];

}

// Defines the starting point
void Maze::setStart(const int x, const int y)
{
    start[0] = x;
    start[1] = y;

    Cell c = grid.getCellAt(x, y);
    c.setState(cell::State::START);
    grid.setCell(c);
}

// Checks if a cell is a wall
bool Maze::isWall(const Cell &c)
{
    return c.getState() == cell::State::OCCUPIED;
}

// Checks if a cell is an outer wall
bool Maze::isOuterWall(const int x, const int y)
{
    return (isNorthWall(y) || isEastWall(x) || isSouthWall(y) || isWestWall(x));
}

// Checks if a cell is a north wall
bool Maze::isNorthWall(const int y)
{
    return y == 0;
}

// Checks if a cell is a south wall
bool Maze::isSouthWall(const int y)
{
    return y == (grid.getNumRows() - 1);
}

// Checks if a cell is an east wall
bool Maze::isEastWall(const int x)
{
    return x == (grid.getNumCols() - 1);
}

// Checks if a cell is a west wall
bool Maze::isWestWall(const int x)
{
    return x == 0;
}

// Checks if a cell is the starting point
bool Maze::isStart(const int x, const int y)
{
    return (x == start[0] && y == start[1]);
}

// The cells along north, south, east, and west of the grid will be set
// to occupied (a wall)
void Maze::initGrid()
{
    std::vector<std::vector<Cell>> gVector = grid.vector();
    int numCols = grid.getNumCols();
    int numRows = grid.getNumRows();

    // Make the north and south walls occupied
    for (int i = 0; i < numCols; i++)
    {
        Cell cNorth = gVector[i][0];
        cNorth.setState(cell::State::OCCUPIED);
        grid.setCell(cNorth);

        Cell cSouth = gVector[i][numRows - 1];
        cSouth.setState(cell::State::OCCUPIED);
        grid.setCell(cSouth);
    }

    // Make the east and west walls occupied
    for (int i = 0; i < numRows; i++)
    {
        Cell cEast = gVector[numCols - 1][i];
        cEast.setState(cell::State::OCCUPIED);
        grid.setCell(cEast);

        Cell cWest = gVector[0][i];
        cWest.setState(cell::State::OCCUPIED);
        grid.setCell(cWest);
    }
}

int Maze::generateRandomNumber(const int min, const int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Seed random number engine
void Maze::seedRandGen()
{
    std::srand(SEED);
}

// Sets the starting point to a random location within the maze that ins't
// a wall
void Maze::randomStart()
{
    // Take care not to place the start point outside of the grid or on the
    // wall by using the following formulae:
    //
    // numCols - 2 so that the start point isn't in the east or west walls
    // numRows - 2 so that the start point isn't in the north or south walls
    int randX = generateRandomNumber(1, grid.getNumCols() - 2);
    int randY = generateRandomNumber(1, grid.getNumRows() - 2);
    setStart(randX, randY);
}

// Returns a random neighbor to the passed in cell, if possible
Cell Maze::getRandomNeighbor(const Cell &c)
{
    int x = c.getXPosition();
    int y = c.getYPosition();

    std::vector<maze::Direction> directions = {
        maze::Direction::NORTH,
        maze::Direction::EAST,
        maze::Direction::SOUTH,
        maze::Direction::WEST
    };

    std::random_shuffle(directions.begin(), directions.end());

    // Cycle through the directions vector until an unvisited cell is found
    // If an unvisited cell is found, return it. If an unvisited cell cannot
    // be found, then return the last cell
    maze::Direction randomDirection;
    Cell randomNeighbor;
    for (int i = 0; i < directions.size(); i++)
    {
        randomDirection = directions[i];
        switch (randomDirection)
        {
        case maze::Direction::NORTH:
            randomNeighbor = grid.getCellAt(x, y - 1);
            break;
        case maze::Direction::EAST:
            randomNeighbor = grid.getCellAt(x + 1, y);
            break;
        case maze::Direction::SOUTH:
            randomNeighbor = grid.getCellAt(x, y + 1);
            break;
        // maze::Direction::WEST
        default:
            randomNeighbor = grid.getCellAt(x - 1, y);
            break;
        }

        if (randomNeighbor.isUnvisited())
        {
            return randomNeighbor;
        }
    }

    return randomNeighbor;
}

// Overloaded operators
std::ostream &operator<<(std::ostream &strm, const Maze &obj)
{
    strm << obj.grid;
    return strm;
}
