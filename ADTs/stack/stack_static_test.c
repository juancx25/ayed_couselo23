#include "stack_static.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*********************************************************************/
// copy stack
stack* stack_copy(stack* s) {
    stack* aux = stack_new(stack_getmaxsize(s));
    while (!stack_isempty(s)) {
        push(aux, pop(s));
    }

    stack* result = stack_new(stack_getmaxsize(s));
    while (!stack_isempty(aux)) {
        push(s, top(aux));
        push(result, pop(aux));
    }

    return result;
}

void print_elem (t_elem e){
    printf("%d\n", *(int*)e);
}

void stack_print(stack* s, void prt (t_elem)) {
    if (!stack_isempty(s)){
        t_elem e = pop(s);
        prt(e);
        stack_print(s, prt);
        push(s, e);
    }
}

void main() {
    printf("OK!\n");

    stack* s = stack_new(10);
    srand(time(NULL));
    while (!stack_isfull(s)) {
        int* aux = (int*)malloc(sizeof(int));
        *aux = rand() % 100;
        push(s, aux);
    }

    stack* s2 = stack_copy(s);

    printf("\npila 1\n");
    stack_print(s, print_elem);

    printf("\npila 2\n");
    stack_print(s2, print_elem);
}
