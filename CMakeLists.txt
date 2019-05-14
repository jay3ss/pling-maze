cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(plingmaze)

include_directories(include)


# Create the libraries
add_library(${PROJECT_NAME}_libcell src/Cell.cpp)
add_library(${PROJECT_NAME}_libgrid src/Grid.cpp)
add_library(${PROJECT_NAME}_libmaze src/Maze.cpp)
add_library(${PROJECT_NAME}_libstackinterface include/pling/StackInterface.h)
add_library(${PROJECT_NAME}_lIblinkedstack include/pling/LinkedStack.h)

# Tell the linker that the libraries are C++
set_target_properties(
    ${PROJECT_NAME}_libstackinterface
    ${PROJECT_NAME}_liblinkedstack
    PROPERTIES LINKER_LANGUAGE CXX
)

# Grid depends on Cell, Maze depends on Grid,
# and LinkedStack depends on StackInterface
target_link_libraries(${PROJECT_NAME}_libgrid ${PROJECT_NAME}_libcell)
target_link_libraries(${PROJECT_NAME}_libmaze ${PROJECT_NAME}_libgrid)
target_link_libraries(${PROJECT_NAME}_liblinkedstack ${PROJECT_NAME}_libstackinterface)


# Create the executable for the Cell class driver and link the library
add_executable(celltest src/cellTest.cpp)
target_link_libraries(celltest ${PROJECT_NAME}_libcell)

# Create the executable for the Grid class driver and link the library
add_executable(gridtest src/gridTest.cpp)
target_link_libraries(gridtest ${PROJECT_NAME}_libgrid)

# Create the executable for the Maze class driver and link the library
add_executable(stackmazetest src/stackMazeTest.cpp)
target_link_libraries(stackmazetest ${PROJECT_NAME}_libmaze ${PROJECT_NAME}_liblinkedstack)
