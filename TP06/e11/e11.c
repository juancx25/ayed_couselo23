#include "../../utils/tree/btree_utils.h"
#include "../../utils/vector/vector_utils.h"

void addToVector(btn* node, void* v){
    t_elem_btree* aux = (t_elem_btree*)malloc(sizeof(t_elem_btree));
    *aux = node->value;
    vector_push((vector*)v, aux);
}

int _main(){
    int NODE_TOTAL = 13;
    btn* head;
    btu_fillWithRandomInts(&head, NODE_TOTAL, 100);
    printf("Tree:\n");
    btn_print(head, btu_intToStr);

    vector* aux_vector = vector_new();

    btn_inorder(head, addToVector, aux_vector);
    printf("\nInorder traversal vector:\n");
    vector_print(aux_vector, printInt);
    vector_empty(aux_vector);

    btn_preorder(head, addToVector, aux_vector);
    printf("\nPreorder traversal vector:\n");
    vector_print(aux_vector, printInt);
    vector_empty(aux_vector);

    btn_postorder(head, addToVector, aux_vector);
    printf("\nPostorder traversal vector:\n");
    vector_print(aux_vector, printInt);
    vector_empty(aux_vector);

    vector_free(aux_vector);

    return 0;
}