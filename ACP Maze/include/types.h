#ifndef TYPES_H
#define TYPES_H

//Needed data types are declared in this file

//a Cell has 2 coordinates and a boolean value denoting whether it has been explored or not
typedef struct cell {
    int x, y;
} Cell;

typedef struct stack{
    //shows current size of the stack
	int size;

    //the array that stores elements of stack
    Cell *arr;
} Stack;

#endif
