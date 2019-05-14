#include <array>
#include <iostream>
#include <string>
#include "pling/Cell.h"

using namespace std;

bool allUnoccupied(array<cell::State, 4>&);
string cellStateToString(cell::State s);

int main()
{
    Cell c;

    cout << "Testing the Cell class\n\n";

    cout << "The cell's default state should be UNVISITED:\n"
         << "---------------------------------------------\n";

    cout << "getState(): returns " << cellStateToString(c.getState())
         << "; should return "
         << cellStateToString(cell::State::UNVISITED) << "\n\n";

    cout << "The cell's default position should be (0, 0):\n"
         << "---------------------------------------------\n";

    cout << "getXPosition(): returns " << c.getXPosition()
         << "; should return 0\n";

    cout << "getYPosition(): returns " << c.getYPosition()
         << "; should return 0\n\n";

    cout << "Set the state of the cell:\n"
         << "--------------------------\n";

    cout << "Set the state of the cell to OCCUPIED\n";
    c = cell::State::OCCUPIED;

    cout << "c.getState() == cell::State::OCCUPIED returns " << (c.getState() == cell::State::OCCUPIED)
         << "; should return 1 (true)\n";

    cout << "c = " << c << endl << endl;

    cout << "Set the state of the cell to UNOCCUPIED\n";
    c = cell::State::UNOCCUPIED;

    cout << "c.getState() == cell::State::UNOCCUPIED returns " << (c.getState() == cell::State::UNOCCUPIED)
         << "; should return 1 (true)\n";

    cout << "c = " << c << "// space" << endl << endl;

    cout << "Set the state of the cell to NONE\n";
    c = cell::State::NONE;

    cout << "c.getState() == cell::State::NONE returns " << (c.getState() == cell::State::NONE)
         << "; should return 1 (true)\n";

    cout << "c = " << c << "// empty string" << endl << endl;

    cout << "Set the state of the cell to UNVISITED\n";
    c = cell::State::UNVISITED;

    cout << "c.getState() == cell::State::UNVISITED returns " << (c.getState() == cell::State::UNVISITED)
         << "; should return 1 (true)\n";

    cout << "c = " << c << endl << endl;
}

bool allUnoccupied(array<cell::State, 4> &nStates)
{
    for (auto &n : nStates)
    {
        if (n != cell::State::UNVISITED)
        {
            return false;
        }
    }

    return true;
}

string cellStateToString(cell::State s)
{
    string str;
    switch (s)
    {
    case cell::State::OCCUPIED:
        str = "OCCUPIED";
        break;
    case cell::State::UNOCCUPIED:
        str = "UNOCCUPIED";
        break;
    case cell::State::UNVISITED:
        str = "UNVISITED";
        break;
    default:
        str = "NONE";
        break;
    }

    return str;
}
