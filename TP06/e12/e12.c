#include "../e11/e11.c"

int cmp_int(void* a, void* b){
    return *(int*)a - *(int*)b;
}

uint32_t find(vector* v, void* value, int l, int r, int (*cmp)(void*, void*)){
    int i = l;
    int found = -1;
    while ((found == -1) && (i < r)){
        if (cmp(vector_get(v, i), value) == 0){
            found = i;
        }
        else i++;
    }
    return found;
}

void _reconstruct(btn** head, vector* inorder, vector* preorder, uint32_t li, uint32_t ri, int (*cmp)(void*, void*)){
    if (!vector_isempty(preorder)){
        void* value = vector_get(preorder, 0);
        uint32_t pos = find(inorder, value, li, ri, cmp);
        if (pos != -1){
            vector_remove(preorder, 0);
            *head = btn_new(*((int*)value));
            if (li < ri-1){
                _reconstruct(&((*head)->left), inorder, preorder, li, pos, cmp);
                _reconstruct(&((*head)->right), inorder, preorder, pos+1, ri, cmp);
            }
        }
    }
}

btn* reconstruct(vector* inorder, vector* preorder, int (*cmp)(void*, void*)){
    btn* newHead;
    _reconstruct(&newHead, inorder, preorder, 0, vector_length(preorder), cmp);
    return newHead;
}

int main(){
    btn* head = btn_new(3);
    btn_insert_value(&head, 2);
    btn_insert_value(&head, 6);
    btn_insert_value(&head, 8);
    btn_insert_value(&head, 4);
    btn_insert_value(&head, 1);
    btn_insert_value(&head, 7);
    btn_insert_value(&head, 9);
    printf("Original tree:\n");
    btn_print(head, btu_intToStr);

    vector* inorder = vector_new();
    vector* preorder = vector_new();

    btn_inorder(head, addToVector, inorder);
    printf("\nInorder traversal vector:\n");
    vector_print(inorder, printInt);

    btn_preorder(head, addToVector, preorder);
    printf("\nPreorder traversal vector:\n");
    vector_print(preorder, printInt);

    btn* copied = reconstruct(inorder, preorder, cmp_int);
    printf("Reconstructed tree:\n");
    btn_print(copied, btu_intToStr);

    return 0;
}