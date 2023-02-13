#include "../../ADTs/vector.h"
#include "time.h"

void printInt(void* value){
    printf("%d ",*((int*)value));
}

/* ------------------------------ SORTING ------------------------------ */

void vu_bubble_sort(vector* v, int (*cmp)(void*, void*)){
    uint32_t len = vector_length(v);
    for (int i=0;i<len-1;i++){
        for (int j=0;j<len-i-1;j++){
            if (cmp(vector_get(v, j), vector_get(v, j+1)) > 0){
                vector_swap(v, j, j+1);
            }
        }
    }
}


void vu_insertion_sort(vector* v, int (*cmp)(void*, void*)){
    uint32_t len = vector_length(v);
    for (int i=1;i<len;i++){
        int j = i;
        while ((j > 0) && (cmp(vector_get(v, j-1), vector_get(v, j)) > 0)){
            vector_swap(v, j, j-1);
            j--;
        }
    }
    return;
}

void vu_selection_sort(vector* v, int (*cmp)(void*, void*)){
    uint32_t len = vector_length(v);
    for (int i=0;i<len;i++){
        int min = i;
        for (int j=i;j<len;j++){
            if (cmp(vector_get(v, j), vector_get(v, min)) < 0){
                min = j;
            }
        }
        vector_swap(v, i, min);
    }
}

void vu_shell_sort(vector* v, int (*cmp)(void*, void*)){
    uint32_t len = vector_length(v);
    for (int i=len/2; i>0; i/=2){
        for (int j=i; j<len; j++){
            for (int k=j-i; k>=0; k-=i){
                if (cmp(vector_get(v, k), vector_get(v, k+i)) > 0){
                    vector_swap(v, k, k+i);
                }
                else break;
            }
        }
    }
}

/* ----------------------------- RANDOMIZER ---------------------------- */

void vu_randomizeInts(vector* v, int size, int threshold){
    srand(time(NULL));
    for (int i=0;i<size;i++){
        int* aux = (int *)malloc(sizeof(int));
        *aux = rand() % threshold;
        vector_push(v, (void*)aux);
    }
}



/* ------------------------------- SEARCH ------------------------------ */

void _vu_linearSearchRecursive(vector* v, uint32_t* pos, void* toFind, int (*cmp)(void*, void*)){
    if (*pos == vector_length(v)){
        *pos = -1;
    }
    else if (cmp(toFind, vector_get(v, *pos)) != 0){
        (*pos)++;
        _vu_linearSearchRecursive(v, pos, toFind, cmp);
    }
    return;
}

uint32_t vu_linearSearchRecursive(vector* v, void* toFind, int (*cmp)(void*, void*)){
    if (vector_length(v) == 1) return 0;
    uint32_t found = 0;
    _vu_linearSearchRecursive(v, &found, toFind, (*cmp));
    return found;
}

uint32_t _vu_binarySearchRecursive(vector* v, uint32_t left, uint32_t right, void* toFind, int (*cmp)(void*, void*)){
    if (left > right) return -1;
    uint32_t middle = (right+left)/2;
    int compared = cmp(toFind, vector_get(v, middle));
    if (compared == 0){
        return middle;
    }
    else if (compared > 1){
        return _vu_binarySearchRecursive(v, middle, right, toFind, cmp);
    }
    else {
        return _vu_binarySearchRecursive(v, left, middle, toFind, cmp);
    }
}

uint32_t vu_binarySearchRecursive(vector* v, void* toFind, int (*cmp)(void*, void*)){
    if (vector_length(v) == 1) return 0;
    return _vu_binarySearchRecursive(v, 0, vector_length(v), toFind, cmp);
}