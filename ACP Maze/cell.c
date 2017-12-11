#include "cell.h"

//creates a new cell from coordinates
Cell CL_new(int x, int y){
    Cell new;
    new.x=x;
    new.y=y;
    return new;
}

//prints contents of a cell to terminal
void CL_print(Cell a){
    printf("x = %d, y = %d\n", a.x, a.y);
}

//given a maze mz returns a cell object representing the entrance
Cell CL_entrance(Maze mz){
    Cell entrance = {};
    MZ_entrance(mz, &entrance.x, &entrance.y);
    return entrance;
}

//given a maze mz returns a cell object representing the exit
Cell CL_exit(Maze mz){
    Cell exit = {};
    MZ_exit(mz, &exit.x, &exit.y);
    return exit;
}

//returns 1 if a and b have the same position, 0 otherwise
int CL_areSame(Cell a, Cell b){
    if(a.x==b.x && a.y==b.y) return 1;
    else return 0;
}

//given a maze mz, a cell to find its neighbors and a Cell array
//of at least 4 elements returns the number of neighbor cells and
//fills the array with Cell objects representing neighbors
int CL_linkedCells(Maze mz, Cell c, Cell linked_cells[]){
    int lc[8];
    int nbl = MZ_linkedCells(mz, c.x, c.y, lc);
    for(int i=0; i<=2*(nbl-1); i+=2){
        linked_cells[i/2].x = lc[i];
        linked_cells[i/2].y = lc[i+1];
    }
    return nbl;
}

//returns the number of unexplored linked cells and fills the array
//(with the size of at least 3) with Cell object representing those cells
int CL_unexploredLinkedCells(Maze mz, Cell c, Cell unexplored_cells[]){
    Cell linked[4] = {};
    int nblu=0, nbl = CL_linkedCells(mz, c, linked);
    Cell* ptr = &unexplored_cells[0];

    //adds neighbor cells which have 0 as explored value to the unexplored_cells
    for (int n=0; n<nbl; n++){
        if( !isExplored(linked[n]) ) { *ptr++ = linked[n]; nblu++; }
    }

}

//given a maze, an array contatining solution cells filled by
//you, and number of solution cells, memorizes the solution path
//to draw it later
void CL_setSolution(Maze mz, Cell solution_cells[], int nb_cells){
    int sc[nb_cells*2];
    for(int a=0; a<nb_cells-1; a++){
        sc[a] = solution_cells[a].x;
        sc[a+1] = solution_cells[a].y;
    }
    MZ_setSolution(mz, sc, nb_cells);
}
