#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Circular Linked List (cll)
 * A circular linked list is a type of linked list in which the first and 
 * the last nodes are also connected to each other to form a circle. 
 * There are basically two types of circular linked list: 
 * 1. Circular Singly Linked List. 
 * 2. Circular Doubly Linked List.
 */

#define t_elem int

// 1. Circular Singly Linked List.
typedef struct csll_node{
    t_elem value;
    struct csll_node* next;    
} csll_node;

// 2. Circular Doubly Linked List.
typedef struct cdll_node{
    t_elem value;
    struct cdll_node* next;
    struct cdll_node* prev;
} cdll_node;

csll_node* csll_newnode (t_elem element){
    csll_node* new_node = (csll_node*) malloc (sizeof(csll_node));
    if (new_node != NULL){
        new_node->value = element;
        new_node->next = NULL;        
    }
    return new_node;
}

cdll_node* cdll_newnode(t_elem element) {
    cdll_node* new_node = (cdll_node*)malloc(sizeof(cdll_node));
    if (new_node != NULL) {
        new_node->value = element;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    return new_node;
}

void csll_add_element(csll_node** last, t_elem element) {
    csll_node* new_node = csll_newnode(element);
    if (*last == NULL) {
        *last = new_node;
        new_node->next = *last;
    } else {
        new_node->next = (*last)->next;
        (*last)->next = new_node;        
    }
}

void csll_remove_element (csll_node** last, t_elem element) {
    if (*last == NULL) return;
    csll_node* aux = *last;
    while (aux->next != *last && aux->next->value != element) {
        aux = aux->next;
    }
    if (aux->next->value == element) {
        csll_node* aux2 = aux->next;
        aux->next = aux2->next;
        aux->next = NULL;
        free(aux2);
    }    
}

