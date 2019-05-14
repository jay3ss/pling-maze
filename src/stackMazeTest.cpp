#include <iostream>
#include "Grid.h"
#include "Maze.h"

using namespace std;

char stateToChar(cell::State state);

int main()
{
    Maze maze(42, 37, false);

    Grid grid = maze.getGrid();
    cout << "The maze is\n\n";

    cout << maze << "\n\n";

    maze.setStart(3, 5);

    Cell startCell = maze.getStart();

    cout << "Starting coordinate is (" << startCell.getXPosition() << ", " << startCell.getYPosition() << ")\n";

    grid = maze.getGrid();

    cout << "Now the maze looks like\n\n" << maze << endl;

    cout << "Test creating a maze with a random start point:\n"
         << "-----------------------------------------------\n\n";

    Maze randMaze(10, 15);

    cout << randMaze << endl;

    cout << "Generated using the seed " << maze.getSeed() << "\n\n";

    cout << "Get a random neighbor:\n"
         << "----------------------\n\n";

    Cell randStart = randMaze.getStart();
    Cell randNeighborCell = randMaze.getRandomNeighbor(randStart);

    cout << "Get random neighbor of starting cell at ("
         << randStart.getXPosition() << ", " << randStart.getYPosition() << ")\n";

    cout << "randMaze.getRandomNeighbor(randStartCell):\n"
         << "Neighbor's coordinates are ("
         << randNeighborCell.getXPosition() << ", "
         << randNeighborCell.getYPosition() << ")\n\n";

    cell::State randState = randMaze.getRandomState();

    cout << "Getting a random state: " << stateToChar(randState) << endl;

    cout << "Generate a maze:\n"
         << "----------------\n\n";

    Maze newMaze(75, 40);

	cout << "Here's the newly generated maze" << "\n\n";
    newMaze.generate();

    cout << newMaze;

    cout << "\nGenerated using seed " << newMaze.getSeed() << endl;
}


char stateToChar(cell::State state)
{
    char c;
    switch (state)
    {
    case cell::State::OCCUPIED:
        c = '#';
        break;
    default:
        c = ' ';
        break;
    }
    return c;
}
