#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Doubly Linked List (DLL)
 * A Doubly Linked List (DLL) contains an extra pointer, typically called
 * previous pointer, together with next pointer and data which are there in
 * singly linked list. dobly linked lists are used when we need to insert or
 * delete a node from any given position.
 */

#define t_elem int

typedef struct dll_node {
    t_elem value;
    struct dll_node* next;
    struct dll_node* prev;
} dll_node;

dll_node* dll_newnode(t_elem element) {
    dll_node* new_node = (dll_node*)malloc(sizeof(dll_node));
    if (new_node != NULL) {
        new_node->value = element;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    return new_node;
}

void dll_addnode(dll_node** head, t_elem element) {
    dll_node* new_node = dll_newnode(element);
    if (*head == NULL) {
        *head = new_node;
    } else {
        dll_node* aux = *head;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = new_node;
        new_node->prev = aux;
    }
}

void _dll_addnode_rec(dll_node** head, dll_node* newnode) {
    if (*head == NULL) {
        *head = newnode;
    } else if ((*head)->next == NULL) {
        (*head)->next = newnode;
        newnode->prev = *head;
    } else {
        _dll_addnode_rec(&(*head)->next, newnode);
    }
}

void dll_addnode_rec(dll_node** head, t_elem element) {
    dll_node* newnode = dll_newnode(element);
    _dll_addnode_rec(head, newnode);
}

void dll_insert_sort(dll_node** head, t_elem element) {
    dll_node* newnode = dll_newnode(element);
    if (*head == NULL) {
        *head = newnode;
    } else if ((*head)->value > element) {
        newnode->next = *head;
        (*head)->prev = newnode;
    } else {
        dll_node* aux = *head;
        while (aux->next != NULL && aux->next->value < element) {
            aux = aux->next;
        }
        newnode->next = aux->next;
        newnode->prev = aux;
        aux->next->prev = newnode;
        aux->next = newnode;
    }
}


void dll_print(dll_node* head) {
    dll_node* aux = head;
    while (aux != NULL) {
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

dll_node* dll_removenode (dll_node** head, t_elem element) {
    dll_node* aux = *head;
    while (aux != NULL && aux->value != element) {
        aux = aux->next;
    }
    if (aux != NULL) {
        if (aux->prev == NULL) {
            *head = aux->next;
        } else {
            aux->prev->next = aux->next;
        }
        aux->next = NULL;
    }
    return aux;
}

int dll_removeelement (dll_node** head, t_elem element) {
    dll_node* aux = dll_removenode (head, element);
    if (aux != NULL) {
        free(aux);
        return 1;
    } else {
        return 0;
    }
}

void dll_removeallelements (dll_node** head, t_elem element){
    while (dll_removeelement(head, element) == 1)
        ;
}



void main() {

    dll_node* h = dll_newnode(0);
    dll_addnode(&h, 1);
    dll_addnode_rec(&h, 3);
    dll_addnode_rec(&h, 5);
    dll_addnode(&h, 7);

    dll_print(h);

    dll_insert_sort(&h, 2);
    dll_insert_sort(&h, 6);

    dll_print(h);


}
