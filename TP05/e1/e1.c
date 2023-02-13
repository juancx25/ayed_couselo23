#include "../../utils/list/list_utils.h"

int cmpInt(int a, int b){
    return a-b;
}

int main(){
    sll_node* head = sll_new_node(1);
    sll_add(&head, 2);
    sll_add(&head, 3);
    sll_add(&head, 3);
    sll_add(&head, 4);
    sll_add(&head, 5);
    sll_add(&head, 5);
    sll_add(&head, 5);
    sll_add(&head, 6);
    sll_add(&head, 7);

    printf("With repeated values:\n");
    sll_print(head);

    lu_remove_repeated(&head, (*cmpInt));

    printf("Without repeated values:\n");
    sll_print(head);
    return 0;
}