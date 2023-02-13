#include <stdio.h>
#include <stdlib.h>
#include "queue_dynamic.h"

queue* queue_new (int maxsize) {
  queue* q = malloc(sizeof(queue));

  q->head = NULL;
  q->tail = NULL;
  q->maxsize = maxsize;
  q->count = 0;

  return q;
}

void queue_free (queue* q) {
  queue_node* aux = q->head;
  while (aux != NULL){
    queue_node* next = aux->next;
    free(aux);
    aux = next;
  }
  free(q);
}

int queue_getsize (queue* q) {
  return q->count;
}

int queue_getmaxsize (queue* q) {
  return q->maxsize;
}

int queue_isfull (queue* q) {
  return (q->count == q->maxsize);
}

int queue_isempty (queue* q) {
  return !(q->count);
}

void enqueue (queue* q, t_elem elem) { 
  if (!queue_isfull(q)){
    queue_node* newTail = (queue_node*)malloc(sizeof(queue_node));
    newTail->value = elem;
    newTail->next = NULL; 
    if (queue_isempty(q)){
      q->head = newTail;
      q->tail = newTail;
    }
    else{
      q->tail->next = newTail;
      q->tail = newTail;
    }
    q->count++;
  }
}

t_elem dequeue (queue* q) {
  t_elem result = q->head->value;
  queue_node* deleted = q->head;
  q->head = q->head->next;
  q->count--;
  free(deleted);
  return result;
}

t_elem peek (queue* q) {
  return (q->head->value);
}