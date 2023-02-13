#include "../../utils/vector/vector_utils.h"

bool vector_isSorted(vector* v, int (*cmp)(void*,void*)){
    uint32_t len = vector_length(v);
    for (int i=0;i<len-1;i++){
        if (cmp(vector_get(v, i), vector_get(v, i+1)) > 0){
            return false;
        }
    }
    return true;
}

int cmp_int(void* a, void* b){
    return *(int*)a - *(int*)b;
}

void bogosort(vector* v, int (*cmp)(void*,void*)){
    uint32_t len = vector_length(v);
    while (!vector_isSorted(v, cmp)){
        srand(time(NULL));
        for (uint32_t i=0;i<len;i++){
            vector_swap(v, i, rand() % len);
        }
    }
}

int main(){
    uint32_t n_elems = 15;
    vector* v = vector_new();
    vu_randomizeInts(v, n_elems, 30);

    clock_t t;

    vector_print(v, printInt);
    t = clock();
    bogosort(v, cmp_int);
    t = clock() - t;
    vector_print(v, printInt);

    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("Bogosort with %d elements took %f seconds to complete.", n_elems, time_taken);

    return 0;
}