#include "../../utils/tree/btree_utils.h"

void btree_mirror(btn* h1, btn** h2){
    if (h1){
        *h2 = btn_new(h1->value);
        btree_mirror(h1->left, &((*h2)->right));
        btree_mirror(h1->right, &((*h2)->left));
    }
}

int main(){
    btn* h1;
    btn* h2;
    btu_fillWithRandomInts(&h1, 7, 10);
    btree_mirror(h1, &h2);

    printf("Original tree:\n");
    btn_print(h1, btu_intToStr);
    printf("Mirrored tree:\n");
    btn_print(h2, btu_intToStr);

    return 0;
}