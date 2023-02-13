#include "../../utils/queue/queue_utils.h"

void qu_invert_rec(queue* q){
    if (!queue_isempty(q)){
        int aux = dequeue(q);
        qu_invert_rec(q);
        enqueue(q, aux);
    }
}

int main(){
    queue* q = queue_new(10);
    qu_fillWithRandomInts(q, 20);

    printf("Regular order:\n");
    qu_printInt(q);

    qu_invert_rec(q);

    printf("Inverse order:\n");
    qu_printInt(q);

    queue_free(q);
    return 0;
}