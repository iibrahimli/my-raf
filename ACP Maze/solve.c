#include "solve.h"

//global variables from main.c
extern int widthg;
extern char *e_statusg;

//function that checks the cells and decides where to go
//saves path inside Stack path
void move(Maze mz, Cell start, Cell end, Stack *path, Stack *branchings){
    ST_push(path, start);

    CL_print(ST_top(path));

    //unexplored neighbors
    Cell linkedUnexplored[3];

    //number of unexplored neighbors
    int nbl;

while(1){
    //printf("%d ",path.size);

    //CL_print(ST_top(&path));

    Cell current = ST_top(path);

    //finish the loop upon reaching the exit cell
    if ( CL_areSame(ST_top(path), end) ) break;

    nbl = CL_unexploredLinkedCells(mz, current, linkedUnexplored);

    //follows a path without branches
    if (nbl == 1){
        //proceeds to the single unexplored one (adds it to stack)
        current = linkedUnexplored[0];
        explore(linkedUnexplored[0]);
        ST_push(path, current);
        continue;
    }

    //if there are branchings, follows the one which makes the Manhattan distance to exit smaller
    //this technique doesn't guarantee fastest solution, but works on mazes with relatively short branchless paths
    //also this will prevent the algorithm from making useless loops most of the time
    else if (nbl == 2){
        if(calc_MD(linkedUnexplored[0], end) < calc_MD(linkedUnexplored[1], end)) {
            current = linkedUnexplored[0];
            explore(linkedUnexplored[0]);
        }
        else {
            current = linkedUnexplored[1];
            explore(linkedUnexplored[1]);
        }
        ST_push(branchings, current);
        continue;
    }

    //upon arriving to a dead-end returns back to the last branching
    else if (nbl == 0){
        while ( ! CL_areSame(current, branchings->arr[branchings->size-1]) ){
            ST_pop(path);
            current=ST_top(path);
        }
        ST_pop(branchings);
        continue;
    }

    //branching
    else if (nbl == 3){
        if(calc_MD(linkedUnexplored[0], end) <= calc_MD(linkedUnexplored[1], end)
           && calc_MD(linkedUnexplored[0], end) <= calc_MD(linkedUnexplored[2], end)) {
            current = linkedUnexplored[0];
            explore(linkedUnexplored[0]);
        }
        else if(calc_MD(linkedUnexplored[1], end) <= calc_MD(linkedUnexplored[0], end)
           && calc_MD(linkedUnexplored[1], end) <= calc_MD(linkedUnexplored[2], end)){
            current = linkedUnexplored[1];
            explore(linkedUnexplored[1]);
        }
        else{
            current = linkedUnexplored[2];
            explore(linkedUnexplored[2]);
        }
        ST_push(branchings, current);
        continue;
    }
}
}

char isExplored(Cell a){
    return e_statusg[widthg*a.y+a.x];
}

void explore(Cell a){
    e_statusg[widthg*a.y+a.x] = 1;
}

//Manhattan distance is simply the sum of moduli of differences in x and y coordinates
int calc_MD(Cell a, Cell b){
    int md=0;
    if(a.x>b.x) md+=a.x-b.x;
    else md+=b.x-a.x;
    if(a.y>b.y) md+=a.y-b.y;
    else md+=b.y-a.y;
    return md;
}
