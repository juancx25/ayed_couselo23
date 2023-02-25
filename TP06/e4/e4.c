#include "../../utils/tree/btree_utils.h"

int equalsChildrenSum(btn* head){
    int result = 1;
    if (head && !btn_isLeaf(head)){
        if (head->value != (head->left->value + head->right->value)) {
            result = 0;
        }
        else result = equalsChildrenSum(head->left) && equalsChildrenSum(head->right);
    }
    return result;
}

int main(){
    btn* head1 = btn_new(5);
    btn_insert_value(&head1, 3);
    btn_insert_value(&head1, 2);
    btn_insert_value(&head1, 1);
    btn_insert_value(&head1, 2);
    btn_insert_value(&head1, 2);
    btn_insert_value(&head1, 0);

    printf("First tree: (with children sum equaling the parent's value)\n");
    btn_print(head1, btu_intToStr);
    equalsChildrenSum(head1) ? printf("EQUALS\n") : printf("DOES NOT EQUAL\n");

    btn* head2;
    btu_fillWithRandomInts(&head2, 6, 100);
    printf("Second tree: random values\n");
    btn_print(head2, btu_intToStr);
    equalsChildrenSum(head2) ? printf("EQUALS\n") : printf("DOES NOT EQUAL\n");

    return 0;
}