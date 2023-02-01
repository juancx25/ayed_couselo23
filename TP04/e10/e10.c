#include "../../ADTs/vector.h"
#include "../../utils/vector/vector_utils.h"
int cmp_int(void* a, void* b){
    return *(int*)a - *(int*)b;
}

void printInt(void* value){
    printf("%d ",*((int*)value));
}

int main(){
    vector* v = vector_new();
    vu_randomizeInts(v, 55, 1000);
    vector_print(v, printInt);

    void* item = vector_get(v, 41);
    uint32_t found = vu_linearSearchRecursive(v, item, (*cmp_int));

    vu_bubble_sort(v, cmp_int);
    item = vector_get(v, 13);
    found = vu_binarySearchRecursive(v, item, (*cmp_int));
    
    return 0;
}