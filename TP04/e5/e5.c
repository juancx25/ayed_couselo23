#include <stdio.h>

double recursive_power(double x, int exp){
    if (exp == 0) return 1;
    if (exp > 0) return x * recursive_power(x, exp-1);
    if (exp < 0) return (1/x) * recursive_power(x, exp+1);
}

int main(){
    int x = 5,
        exp = -2;
    double result = recursive_power(x, exp);
    printf("%f^%d = %0.4f\n", x, exp, result);
    return 0;
}