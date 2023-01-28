#include "../../ADTs/vector.h"
#include <stdio.h>

void printInt(void* elem){
    int* pepe = (int*)elem;
    printf("%d ",*((int*)elem));
}

int main(){
    int v_size = 5;
    vector* v = vector_init(v_size);
    
    for (int i=0;i<v_size;i++){
        int* aux = (int*)malloc(sizeof(int));
        *aux = i;
        vector_add(v, (void*)aux);
    }

    vector_print(v, *printInt);

    

    return 0;
}