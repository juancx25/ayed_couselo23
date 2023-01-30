#include "../../ADTs/vector.h"
#include <time.h>

void _vectorInt_max(vector* v, int pos, int* max){
    if (pos == vector_length(v)) return;
    int* val = (int*)vector_get(v, pos);
    if (*val > *max){
        *max = *val;
    }
    return _vectorInt_max(v, ++pos, max);
}

int vectorInt_max(vector* v){
    if (vector_length(v) == 0) return 0;
    int* result = (int*)vector_get(v, 0);
    _vectorInt_max(v, 0, result);
    return *result;
}

void fillWithRandomInts(vector* v, int size){
    srand(time(NULL));
    for (int i=0;i<size;i++){
        int* aux = (int *)malloc(sizeof(int));
        *aux = rand() % 100;
        vector_add(v, (void*)aux);
    }
}

void printInt(void* elem){
    int* pepe = (int*)elem;
    printf("%d ",*((int*)elem));
}


int main(){
    vector* v = vector_new();
    fillWithRandomInts(v, 10);
    vector_print(v, *printInt);
    printf("El máximo es: %d\n", vectorInt_max(v));

    return 0;
}