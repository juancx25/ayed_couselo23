#include "../../ADTs/tree/btree_base.h"
#include <time.h>

void btu_intToStr(btn* node, char* str) {
    if (!node) return;    
    sprintf(str, "(%03d)", node->value);    
}

void btu_fillWithRandomInts(btn** head, int totalNodes, int threshold){
    srand(time(NULL));
    *head = btn_new(rand() % threshold);
    for (int i=0;i<totalNodes;i++){
        btn_insert_value(head, rand() % threshold);
    }
    return;
}