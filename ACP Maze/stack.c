#include "stack.h"
#include <unistd.h>

Stack ST_new(){
	Stack new;
	new.size = 0;
	return new;
}

void ST_push(Stack *st, Cell n){
	st->arr[st->size-1] = n;
	st->size++;
}

void ST_pop(Stack *st){
	if(st->size==0) printf("Error: stack is empty!\n");
	else {
		st->size--;
	}
}

Cell ST_top(Stack *st){
	if(st->size==0) printf("Error: stack is empty!\n");
	else return st->arr[st->size-1];
}
