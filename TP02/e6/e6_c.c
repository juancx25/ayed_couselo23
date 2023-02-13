#include "../../utils/vector/vector_utils.h"

int cmp_int(void* a, void* b){
    return *(int*)a - *(int*)b;
}

int main(){
    vector* v = vector_new();
    vu_randomizeInts(v, 20, 1000);

    vector_print(v, (*printInt));
    vu_selection_sort(v, (*cmp_int));
    vector_print(v, (*printInt));
    return 0;
}