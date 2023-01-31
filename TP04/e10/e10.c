#include "../../ADTs/vector.h"
#include "../../utils/randomizer.c"
#include "../../utils/vector_sort.c"
#include "../../utils/vector_search.c"

void _linear_search(vector* v, uint32_t* pos, void* toFind, int (*cmp)(void*, void*)){
    if (*pos == vector_length(v)){
        *pos = -1;
    }
    else if (cmp(toFind, vector_get(v, *pos)) != 0){
        (*pos)++;
        _linear_search(v, pos, toFind, cmp);
    }
    return;
}

uint32_t linear_search(vector* v, void* toFind, int (*cmp)(void*, void*)){
    if (vector_length(v) == 1) return 0;
    uint32_t found = 0;
    _linear_search(v, &found, toFind, (*cmp));
    return found;
}


uint32_t _binary_search(vector* v, uint32_t left, uint32_t right, void* toFind, int (*cmp)(void*, void*)){
    if (left > right) return -1;
    uint32_t middle = (right+left)/2;
    int compared = cmp(toFind, vector_get(v, middle));
    if (compared == 0){
        return middle;
    }
    else if (compared > 1){
        return _binary_search(v, middle, right, toFind, cmp);
    }
    else {
        return _binary_search(v, left, middle, toFind, cmp);
    }
}

uint32_t binary_search(vector* v, void* toFind, int (*cmp)(void*, void*)){
    if (vector_length(v) == 1) return 0;
    return _binary_search(v, 0, vector_length(v), toFind, cmp);
}

int cmp_int(void* a, void* b){
    return *(int*)a - *(int*)b;
}

void printInt(void* value){
    printf("%d ",*((int*)value));
}

int main(){
    vector* v = vector_new();
    vu_randomizeInts(v, 15, 100);
    vector_print(v, printInt);

    void* item = vector_get(v, 5);
    uint32_t found = linear_search(v, item, (*cmp_int));

    vu_bubble_sort(v, cmp_int);
    found = binary_search(v, item, (*cmp_int));
    
    return 0;
}