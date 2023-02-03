#include "../../ADTs/vector.h"

void printInt(void* elem){
    int* pepe = (int*)elem;
    printf("%d ",*((int*)elem));
}

int main(){
    int v_size = 12;
    vector* v = vector_init(v_size);
    
    for (int i=0;i<v_size;i++){
        int* aux = (int*)malloc(sizeof(int));
        *aux = i;
        vector_push(v, (void*)aux);
    }

    vector_print(v, *printInt);

    void* removed = vector_remove(v, 3);
    free(removed);
    vector_print(v, *printInt);

    int newVal = 12;
    removed = vector_get(v, 0);
    vector_set(v, 0, (void*)&newVal);
    free(removed);
    vector_print(v, *printInt);

    vector_swap(v, 1, 6);
    vector_print(v, *printInt);

    vector_free(v);
    return 0;
}