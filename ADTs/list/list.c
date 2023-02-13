/*#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list *list_new(int maxsize) {
  list* newList = (list*)malloc(sizeof(list));
  newList->head = NULL;
  newList->maxsize = maxsize;
  newList->count = 0;
}

bool list_isempty(list *L) {
  return !(L->count);
}

bool list_isfull(list *L) {
  return (L->count == L->maxsize);
}

int list_length(list *L) {
  return L->count;
}

t_elem list_get(list *L, int index) {
  t_elem result;
  if (index < list_length(L)){
    list_node* aux = L->head;
    for (int i=0;i<L->count;i++){
      aux = aux->next;
    }
  }
}

int list_search(list *L, t_elem elem) {
  t_elem result = -1;
  list_node* aux = L->head;
  int i = 0;
  while ((result == -1) && (i < list_length(L))){
    if (aux->value == elem){
      result = i;
    }
    else {
      i++;
      aux = aux->next;
    }
  }
  return result;
}

void list_insert(list *L, int index, t_elem elem) {
  list_node* aux = L->head;
    if (!list_isfull(L)){
      if (index == 0){
      L->head = (list_node*)malloc(sizeof(list_node));
      L->head->value = elem;
      L->head->next = aux;
      L->count++;
    }
    else if (index < list_length(L)){
      for (int i=0;i<index-1;i++){
        aux = aux->next;
      }
      list_node* newNode = (list_node*)malloc(sizeof(list_node));
      newNode->value = elem;
      newNode->next = aux->next;
      aux->next = newNode;
      L->count++;
    }
  }
}

void list_delete(list *L, int index) {
  list_node* aux = L->head;
  if (index < list_length(L)){
    if (index == 0){
      L->head = L->head->next;
      free(aux);
      L->count--;
    }
    else {
      for (int i=0;i<index-1;i++){
        aux = aux->next;
      }
      list_node* newNext = aux->next->next;
      free(aux->next);
      aux->next = newNext;
      L->count--;
    }
  }
}

void list_traverse(list *L, bool look(t_elem elem, int index, void *ctx), void *ctx) {
  list_node *node = L->head;
  int index = 0;

  while (node != NULL && look(node->value, index, ctx)) {
    node = node->next;
    index++;
  }
}*/