#include "../../ADTs/queue/queue_dynamic.h"
#include <time.h>

void qu_printInt(queue* q){
    int length = queue_getsize(q);
    for (int i=0;i<length;i++){
        int value = dequeue(q);
        printf("%d ", value);
        enqueue(q, value);
    }
    printf("\n");
}

void qu_fillWithRandomInts(queue* q, int threshold){
    srand(time(NULL));
    while (!queue_isfull(q)){
        int* aux = (int*)malloc(sizeof(int));
        *aux = rand() % threshold;
        enqueue(q, *aux);
    }
}