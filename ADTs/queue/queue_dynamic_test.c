#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue_dynamic.h"


/**************************************************************/

queue* queue_copy (queue* q){
    queue* aux = queue_new(queue_getmaxsize(q));
    while (!queue_isempty(q)){
        enqueue(aux, dequeue(q));
    }
    
    queue* result = queue_new(queue_getmaxsize(aux));
    while (!queue_isempty(aux)){
        enqueue(q, peek(aux));
        enqueue(result, dequeue(aux));
    }
    queue_free(aux);
    return result;
}



void main(){
    int maxsize = 10;
    queue* q = queue_new(maxsize);

    srand(time(NULL));

    while (!queue_isfull(q)){
        int* aux = (int*)malloc(sizeof(int));
        *aux = rand()%100;
        enqueue(q, *aux);
    }

    queue* q2 = queue_copy(q);

    for(int i=0; i<maxsize; i++){
        t_elem aux = dequeue(q);
        printf("%d\n", aux);

        aux = dequeue(q2);
        printf("%d\n", aux);
    }

    queue_free(q);
    queue_free(q2);

}
