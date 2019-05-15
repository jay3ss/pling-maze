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

## Current status
As of right now (5/14/2019), the printing of the maze is a little... uh...
interesting. It doesn't really *look* like a maze, but with a little work it'll
get there. Here's an example of what a generated maze currently looks like

```
###########################################################################
##  ## ## # ##  #  ##   #### ### ##  #  ###    #   #####  # #   ##  # ### #
##   # ##    ####   #           ### ###  ### #  #     ##  #  ##  ### # ####
#   #   ####    ###      ###   ## #  ##    ##  # #  ##    ###  # ###   ## #
# #   # ## ##  #####  # # # # #  ##    # # #    ###   ####   ##  #    #  ##
# #### # ##     ##      #  ##### #   ####        # #     ###  #   ##### ###
#  #  ##    #   ###  #      ## #  ###  #####  #    # #       #    #### #  #
##   ##    # ####   ######## # #  #######     ### ##  ####  #   ### #   # #
## #  # ###  ## ##   #   #   ##  # # ##    ## ###  # #   # #  ###  ####   #
### # ####   ###   ## ##   ##### #  #  ###### # #### #  ##     ##    #  ###
## ### ###  ##  # ## # ##   #  ##### #   #    #### #  # # #     # #   #   #
# #         #    ###  ## ###    ## ## # # # ## ##### ##### #  # # # ##    #
#   ### # ##     # # ##  ## ###  # # ### ## #      ## ##### #  #####  # # #
#  #  ######  # ##    # ####      ## #   ######    # ## # ###      # # ####
# #### ##### ###  ## # ## #    #####   # ### ##  ####    #### ### # #  ####
# #### ## #### ###### #    #  ### # #  ###  # ####     ###    ##   # ## # #
## ### # #    #  #   ##        ## #   #   ### ## # ##   #  #   # #       ##
#   #  #####    ## ###   #### ## #   ## #   ###### # ##### # ### # ## # ###
## ##   ## ##    # # ### #    #   # #    ##      # # # # # ##   # #  #   ##
###  ###       ## #  #  ##  #  ###  # # #    #  # #    ##   ###### ##  ####
## # # # #    ###    #### # #   # #  ## ### #      ##        #  # #### ####
# #  #######  #####  #  # ##   # #    # # # ## #          # ## # #   ###  #
##    ##  # # # ### ## #   ##  ######   #  # ##  # ### #####      # ##   ##
####   ## # # ##  # #   #  #  # #  #  ## ##   #### #  # ####   ## # #### ##
# #  #  # ####  ###  ##   #     # # #   #### # # # #### ##  ##   # ###  # #
##  # ##  #  # #     ##  ### ###   ## # # ##    #  #  #  # ##   # # # ### #
# #  ###### # ## ## ## #####    ## # #     # # #  #  # # ### # ## # #   ###
# ## # # ##  #  #   ## #  ##  # ### #  ##     #   #### #   ####### ##   # #
#  #    #  ###      ### # #   #  ####  #   #      #######   ## ###   # #  #
## #    # # ## #####  #  # #   #     ### #   ##  #   ## # ##  # ### #  ####
# #  ## ## # ## ##    ##  ####  ## ### # #   ### ## ## ## ##  ###   ## #  #
## ### ####  ## ## ###   #### ##  ### ### #####  # ## # #  #   # ###   ## #
###  ## #    #   ####### #    ##  ##  #### ##     #    #  ## ######    # ##
# # ### ## # ####  #### ## ####  #  ### ### #   ### # ##   #  # ##    ##  #
###  ##### ## # #####  ## #    # ###   ##  ## ## #    #  #   ###  # ## ## #
###  ### #     ####     ### # ##  ## # ###  ## #   # #### # # # # #  ### ##
#   ## #   ### # #         #  #  # # # # #  ## # # ###### # #    #### #   #
##  #  ##      #  ## # #### ##    #   ## # # ##    ###  #     ### ###  # ##
##  # # ##     ##   #########  #      ###  ######   # # #  #    #     ##  #
###########################################################################
```

Notice how the walls are only `#`s and they aren't really distinct? That's one
of the first things on the todo list (i.e., make this look like a legitimate
maze versus some crude QR code).
