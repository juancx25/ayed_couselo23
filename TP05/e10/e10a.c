#include "../../utils/stack/stack_utils.h"

void printInt(void* value){
    printf("%d ", *((int*)value));
}

int sum(stack* s){
    int result = 0;
    if (!stack_isempty(s)){
        void* value = pop(s);
        result = *((int*)value) + sum(s);
        push(s, value);
    }
    return result;
}

int main(){
    stack* s = stack_new(10);
    su_fillWithRandomInts(s, 10);

    su_printStack_rec(s, printInt);
    printf("\nThe sum of the elements is: %d\n", sum(s));
    su_printStack_rec(s, printInt);

    return 0;
}