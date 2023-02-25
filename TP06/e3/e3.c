#include "../../utils/tree/btree_utils.h"

void sumNode(btn* node, void* ctx){
    *((int*)ctx) += node->value;
}

int main(){
    btn* head;
    btu_fillWithRandomInts(&head, 11, 20);
    btn_print(head, btu_intToStr);

    int sum_adt = 0;
    btn_inorder(head, sumNode, &sum_adt);
    printf("The node sum (with ADT's inorder traversal) is: %d\n", sum_adt);

    btn_free(&head);
    return 0;
}