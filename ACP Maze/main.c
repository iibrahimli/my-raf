#include <stdio.h>
#include "Maze.h"
#include "types.h"
#include "cell.h"
#include "solve.h"
#include "stack.h"

char *e_statusg;
int widthg;

int main(){
    Maze mz = MZ_new(20,12,MZ_HARD);

    int width, height;
    MZ_size(mz, &width, &height);

    printf("width=%d, height=%d\n", width, height);

    //two stacks holding current path and branchings along the way respectively
    Stack path = ST_new();
    path.arr = (Cell *) calloc(width*height, sizeof(Cell));
    Stack branchings = ST_new();
    branchings.arr = (Cell *) calloc(width*height, sizeof(Cell));

    ST_push(&path, CL_new(3,5));
    CL_print(ST_top(&path));
    ST_pop(&path);

    char *e_status = (char*) calloc(width*height, sizeof(char));

    e_statusg=e_status;
    widthg=width;

    Cell entrance = CL_entrance(mz);
    Cell end = CL_exit(mz);

    //everything happens here
    move(mz, entrance, end, &path, &branchings);

    free(e_statusg);

    //after the function is done, the path stack will hold solution cells
    //we use the underlying array of our path stack as solution
    CL_setSolution(mz, path.arr, path.size);

    MZ_saveImg(mz,"myFirstMaze.ppm");
    MZ_free(mz);

    return 0;
}
