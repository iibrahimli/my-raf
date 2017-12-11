#ifndef SOLVE_H
#define SOLVE_H

#include "Maze.h"
#include "types.h"
#include "cell.h"
#include "stack.h"


/*
    This function uses so-called "Manhattan distance"
    Manhattan distance is the shortest path between two points in a square grid
    where it is only possible to move along the grids, and is different from
    Euclidean distance. In any direction you move in the grid, Manhattan distance
    either decreases or increases by 1.
*/

//calculates Manhattan Distance between given two cells
int calc_MD(Cell a, Cell b);

//expects a 2D array "e_status" created in main and each value of which stores 1 if
//the corresponding cell is explored and 0 otherwise
char isExplored(Cell a);

//makes given cell explored
void explore(Cell a);

//gets current (starting) and exit cells and pointers to needed stacks
void move(Maze mz, Cell start, Cell end, Stack *path, Stack *branchings);

#endif
