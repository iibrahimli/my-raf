#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"


//creates a new stack with maximum capacity given in size
Stack ST_new();

//adds new element to the top of the stack
void ST_push(Stack *st, Cell n);

//removes the last element from the stack
void ST_pop(Stack *st);

//returns the top element in the stack
Cell ST_top(Stack *st);

#endif
