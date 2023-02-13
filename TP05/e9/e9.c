#include "../../utils/queue/queue_utils.h"

int main(){
    queue* q = queue_new(20);

    qu_fillWithRandomInts(q, 100);
    qu_printInt(q);

    queue_free(q);
    return 0;
}