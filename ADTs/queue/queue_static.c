#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#include "queue_static.h"

queue* queue_new(int maxsize){
    queue* q = (queue*)malloc(sizeof(queue));
    q->a = (t_elem*)calloc(sizeof(t_elem), maxsize);
    q->maxsize = maxsize;
    q->count = 0;
}

void queue_free (queue* q){
    free(q->a);
    free(q);
}

int queue_getmaxsize(queue* q){
    return q->maxsize;
}

int queue_getsize(queue* q){
    return q->count;
}

int queue_isfull (queue* q){
    return (q->maxsize == q->count);
}

int queue_isempty (queue* q){
    return !(q->count);
}

void enqueue (queue* q, t_elem elem){    
    if (!queue_isfull(q)){
        q->a[q->count++] = elem;
    }
}

t_elem dequeue (queue* q){
    t_elem result = 0; // Should have a neutral element to return in case of the queue being empty
    if (!queue_isempty(q)){
        result = q->a[0];
        memcpy(q->a, &(q->a[1]), sizeof(t_elem*)*q->count);
        q->count--;
    }
    return result;
}

t_elem peek (queue* q){
    if (!queue_isempty(q)){
        return q->a[0];
    }
    return 0;
}




