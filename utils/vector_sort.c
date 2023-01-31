#include "../ADTs/vector.h"

void vu_bubble_sort(vector* v, int (*cmp_int)(void*, void*)){
    uint32_t len = vector_length(v);
    for (int i=0;i<len-1;i++){
        for (int j=0;j<len-i-1;j++){
            if (cmp_int(vector_get(v, j), vector_get(v, j+1)) > 0){
                vector_swap(v, j, j+1);
            }
        }
    }
}