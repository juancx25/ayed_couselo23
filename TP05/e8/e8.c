#include "../../utils/stack/stack_utils.h"

void printInt(void* value){
    printf("%d ", *((int*)value));
}

void printStack_iter(stack* s, void (*print)(void*)){
    int length = stack_getsize(s);
    stack* aux = stack_new(stack_getmaxsize(s));
    while (!stack_isempty(s)){
        push(aux, pop(s));
    }
    while (!stack_isempty(aux)){
        t_elem value = pop(aux);
        print(value);
        push(s, value);
    }
}

void printStack_rec(stack* s, void (*print)(void*)){
    if (!stack_isempty(s)){
        void* value = pop(s);
        printStack_rec(s, print);
        push(s, value);
        print(value);
    }
}

int main(){
    stack* s = stack_new(30);
    su_fillWithRandomInts(s, 100);

    printf("Iterative version:\n");
    printStack_iter(s, printInt);
    printf("\n");

    printf("Recursive version:\n");
    printStack_rec(s, printInt);
    printf("\n");

    return 0;
}