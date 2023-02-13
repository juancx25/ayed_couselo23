#include "../../utils/queue/queue_utils.h"

int sum_iter(queue* q){
    int length = queue_getsize(q);
    int result = 0;
    for (int i=0;i<length;i++){
        int aux = dequeue(q);
        result += aux;
        enqueue(q, aux);
    }
    return result;
}

int sum_rec(queue* q){
    int r = 0;
    if (!queue_isempty(q)){
        int aux = dequeue(q);
        r = aux + sum_rec(q);
        enqueue(q, aux);
    }
    return r;
}



int main(){
    queue* q = queue_new(1000);

    qu_fillWithRandomInts(q, 100);
    //qu_printInt(q);

    printf("Iterative sum: %d\n", sum_iter(q));
    printf("Recursive sum: %d\n", sum_rec(q));

    queue_free(q);
    return 0;
}