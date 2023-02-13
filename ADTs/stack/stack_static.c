#include <stdio.h>
#include <stdlib.h>

#include "stack_static.h"

stack* stack_new(int maxsize){
    /*COMPLETAR*/
}

void stack_free(stack* s){
    /*COMPLETAR*/
}

int stack_getsize(stack* s){
    /*COMPLETAR*/
}

int stack_getmaxsize(stack* s){
    /*COMPLETAR*/
}

void push(stack* s, t_elem elem){
    /*COMPLETAR*/
}

t_elem pop(stack* s){
    /*COMPLETAR*/
}

t_elem top(stack* s){
    /*COMPLETAR*/
}

int stack_isempty(stack* s){
    /*COMPLETAR*/
}

int stack_isfull(stack* s){
    /*COMPLETAR*/
}

void stack_destroy(stack* s, void elem_free(void*)){
    /*COMPLETAR*/ 
}


