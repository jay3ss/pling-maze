cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
project(csis211lab04)

# Create the libraries
add_library(libcell Cell.cpp)
add_library(libgrid Grid.cpp)
add_library(libmaze Maze.cpp)
add_library(libstackinterface StackInterface.h)
add_library(liblinkedstack LinkedStack.h)

# Tell the linker that the libraries are C++
set_target_properties(
    libstackinterface
    liblinkedstack
    PROPERTIES LINKER_LANGUAGE CXX
)

# Grid depends on Cell, Maze depends on Grid,
# and LinkedStack depends on StackInterface
target_link_libraries(libgrid libcell)
target_link_libraries(libmaze libgrid)
target_link_libraries(liblinkedstack libstackinterface)


# Create the executable for the Cell class driver and link the library
add_executable(celltest cellTest.cpp)
target_link_libraries(celltest libcell)

# Create the executable for the Grid class driver and link the library
add_executable(gridtest gridTest.cpp)
target_link_libraries(gridtest libgrid)

# Create the executable for the Maze class driver and link the library
add_executable(stackmazetest stackMazeTest.cpp)
target_link_libraries(stackmazetest libmaze liblinkedstack)
