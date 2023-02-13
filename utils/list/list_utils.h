#include "../../ADTs/list/lists_sll.c"
#include <time.h>

void printInt(void* value){
    printf("%d ",*((int*)value));
}

sll_node** lu_new_randomInts(int size, int threshold){
    srand(time(NULL));
    sll_node** head;
    *head = sll_new_node(rand() % threshold);
    sll_node** aux = head;
    for (int i=0;i<size;i++){
        sll_node* newNode = sll_new_node(rand() % threshold);
        (*aux)->next = newNode;
        aux = &(*aux)->next;
    }
    return head;
}

int lu_find(sll_node* head, t_elem value, int (*cmp)(t_elem,t_elem)){
    sll_node* aux = head;
    int found = 0;
    while ((!found) && (aux)){
        if (cmp(aux->value, value) == 0){
            found = 1;
        }
        aux = aux->next;
    }
    return found;
}

void lu_remove_repeated(sll_node** head, int (*cmp)(t_elem,t_elem)){
    sll_node* node = *head;
    sll_node* aux = sll_new_node((*head)->value);
    while(node){
        if (!lu_find(aux, node->value, cmp)){
            sll_add(&aux, node->value);
        }
        node = node->next;
    }
    free(*head);
    *head = aux;
    return;
}
