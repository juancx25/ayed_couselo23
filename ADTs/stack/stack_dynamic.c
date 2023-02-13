#include <stdio.h>
#include <stdlib.h>

#include "stack_dynamic.h"

stack* stack_new(int maxsize) {
  stack* s = (stack*)malloc(sizeof(stack));
  s->head = NULL;
  s->maxsize = maxsize;
  s->count = 0;
}

void stack_free(stack* s) {
  stack_node* aux = s->head;
  for (int i=0;i<s->count;i++){
    stack_node* next = aux->next;
    free(aux);
    aux = next;
  }
  free(s);
}

int stack_getsize(stack* s) {
  return s->count;
}

int stack_getmaxsize(stack* s) {
  return s->maxsize;
}

int stack_isempty(stack* s) {
  return !(s->count);
}

int stack_isfull(stack* s) {
  return (s->count == s->maxsize);
}

void push(stack* s, t_elem elem) {
  if (!stack_isfull(s)){
    stack_node* newHead = (stack_node*)malloc(sizeof(stack_node));
    newHead->value = elem;
    newHead->next = s->head;
    s->head = newHead;
    s->count++;
  }
}

t_elem pop(stack* s) {
  t_elem result;
  if (!stack_isempty(s)){
    stack_node* deleted = s->head;
    s->head = s->head->next;
    result = deleted->value;
    free(deleted);
    s->count--;
  }
  return result;
}

t_elem top(stack* s) {
  return s->head->value;
}

void stack_destroy(stack* s, void elem_free(t_elem)){
  stack_node* aux = s->head;
  for (int i=0;i<s->count;i++){
    stack_node* next = aux->next;
    elem_free(aux->value);
    free(aux);
    aux = next;
  }
  free(s);
}