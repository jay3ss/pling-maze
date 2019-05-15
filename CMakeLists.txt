cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-std=c++11")
project(plingmaze VERSION "0.0.1")

include_directories(include)

# Create the libraries
add_library(${PROJECT_NAME}_libcell src/Cell.cpp)
add_library(${PROJECT_NAME}_libgrid src/Grid.cpp)
add_library(${PROJECT_NAME}_libmaze src/Maze.cpp)

# Grid depends on Cell, Maze depends on Grid
target_link_libraries(${PROJECT_NAME}_libgrid ${PROJECT_NAME}_libcell)
target_link_libraries(${PROJECT_NAME}_libmaze ${PROJECT_NAME}_libgrid)

# Create the executable for the Cell class driver and link the library
add_executable(celltest src/cellTest.cpp)
target_link_libraries(celltest ${PROJECT_NAME}_libcell)

# Create the executable for the Grid class driver and link the library
add_executable(gridtest src/gridTest.cpp)
target_link_libraries(gridtest ${PROJECT_NAME}_libgrid)

# Create the executable for the Maze class driver and link the library
add_executable(stackmazetest src/stackMazeTest.cpp)
target_link_libraries(stackmazetest ${PROJECT_NAME}_libmaze)

if(BUILD_TESTING)
    find_package(Catch2 REQUIRED)
    # Tests
    # Setup for the main file
    add_library(testsmain tests/tests-main.cpp)
    target_link_libraries(testsmain Catch2::Catch2)

    # Test the Cell class
    add_executable(testcell tests/test-cell.cpp)
    target_link_libraries(testcell testsmain)

    # Make tests discoverable
    include(CTest)
    include(Catch)
    catch_discover_tests(testcell)

    # use `make test` to run the tests
    enable_testing()
    add_test(NAME CellTest COMMAND testcell)
endif()
