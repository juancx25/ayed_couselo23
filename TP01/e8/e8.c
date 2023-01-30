#include "../../ADTs/fraction.h"

int main(){
    fraction* f1 = fraction_new();

    fraction_setNum(f1,10);
    fraction_setDen(f1,-4);

    fraction_print(f1);
    printf("\n");

    fraction_simplify(f1);
    int n = fraction_getNum(f1);
    double d = fraction_getValue(f1);

    fraction* f2 = fraction_init(3,5);
    
    fraction* f3 = fraction_sum(f1, f2);

    fraction* f4 = fraction_subtract(f2, f1);

    fraction* f5 = fraction_multiply(f1,f2);

    fraction* f6 = fraction_divide(f1,f2);

    return 0;
}