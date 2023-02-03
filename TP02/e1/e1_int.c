#include "../../ADTs/vector.h"

void printInt(int value){
    printf("%d ", value);
}

int main(){
    vector* v = vector_new();
    int v_size = 6;
    for (int i=0;i<v_size;i++){
        vector_push(v, i);
    }

    vector_print(v, *printInt);

}