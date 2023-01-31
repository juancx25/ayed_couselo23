#include "../ADTs/vector.h"
#include "time.h"

void vu_randomizeInts(vector* v, int size, int threshold){
    srand(time(NULL));
    for (int i=0;i<size;i++){
        int* aux = (int *)malloc(sizeof(int));
        *aux = rand() % threshold;
        vector_add(v, (void*)aux);
    }
}