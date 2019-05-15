# pling-maze
Generates mazes!

## Background
This started out as a project for a data structures course that I was taking.
It turned out to be pretty fun so I decided to make it its own project.

## Dependencies
If you don't want to run the tests, then none (aside from CMake)! Otherwise,
you'll need to have [Catch2](https://github.com/catchorg/Catch2) installed
somewhere.

## Getting this thing to work
To do an out of source build

```
$ git clone https://github.com/jay3ss/pling-maze
$ cd pling-maze
$ mkdir build && cd build
$ cmake ..
$ make
```

### To test or not to test
If you want to compile and run the tests too, you'll need to let CMake know

```
$ git clone https://github.com/jay3ss/pling-maze
$ mkdir build && cd build
$ cmake .. -DCMAKE_PREFIX_PATH=/path/to/Catch2/ -DBUILD_TESTING=ON
$ make
$ make test
```
