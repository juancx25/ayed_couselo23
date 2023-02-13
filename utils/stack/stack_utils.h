#include "../../ADTs/stack/stack_dynamic.h"
#include <time.h>

void su_fillWithRandomInts(stack* s, int threshold){
    srand(time(NULL));
    while (!stack_isfull(s)){
        int* aux = (int*)malloc(sizeof(int));
        *aux = rand() % threshold;
        push(s, aux);
    }
}

void su_printStack_rec(stack* s, void (*print)(void*)){
    if (!stack_isempty(s)){
        void* value = pop(s);
        su_printStack_rec(s, print);
        push(s, value);
        print(value);
    }
}