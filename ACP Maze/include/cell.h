#ifndef CELL_H
#define CELL_H

#include "Maze.h"
#include "types.h"
#include "stack.h"
#include "solve.h"

//creating new cell from its integer coordinates
Cell CL_new(int x, int y);

//prints contents of a cell to terminal
void CL_print(Cell a);

//given a maze mz returns a cell object representing the entrance
Cell CL_entrance(Maze mz);

//given a maze mz returns a cell object representing the exit
Cell CL_exit(Maze mz);

//return 1 if a and b have the same position, 0 otherwise
int CL_areSame(Cell a, Cell b);

//given a maze mz, a cell to find its neighbors and a Cell array
//of at least 4 elements returns the number of neighbor cells and
//fills the array with Cell objects representing neighbors
int CL_linkedCells(Maze mz, Cell c, Cell linked_cells[]);

//returns the number of unexplored linked cells and fills the array
//(with the size of at least 3) with Cell object representing those cells
int CL_unexploredLinkedCells(Maze mz, Cell c, Cell unexplored_cells[]);

//given a maze, an array contatining solution cells filled by
//you, and number of solution cells, memorizes the solution path
//to draw it later
void CL_setSolution(Maze mz, Cell solution_cells[], int nb_cells);

#endif
