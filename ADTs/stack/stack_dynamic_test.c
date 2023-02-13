#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack_dynamic.h"

/*********************************************************************/
// copy stack
stack* stack_copy(stack* s){
    stack* aux = stack_new(stack_getmaxsize(s));
    while (!stack_isempty(s)){
        push(aux, pop(s));
    }
    
    stack* result = stack_new(stack_getmaxsize(s));    
    while (!stack_isempty(aux)){
        push(s,top(aux));
        push(result, pop(aux));
    }

    return result;
}

void main(){

    printf("OK!\n");

    stack* s = stack_new(30);
    srand(time(NULL));
    while (!stack_isfull(s)){
        int* aux = (int*)malloc(sizeof(int));
        *aux = rand()%100;
        push(s, aux);
    }

    stack* s2 = stack_copy(s);

    printf("\npila 1\n");
    while (!stack_isempty(s)){
        printf("%d ", *((int*)pop(s)));
    }
    printf("\n");
    
    printf("\npila 2\n");
    while (!stack_isempty(s2)){
        printf("%d ", *((int*)pop(s2)));
    }
    printf("\n");

    stack_destroy(s, free);
    stack_destroy(s2, free);

}
