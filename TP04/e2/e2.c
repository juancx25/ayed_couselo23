#include <stdio.h>

int factorial(int n){
    if (n < 2) return 1;
    return n*factorial(n-1);
}

int main(){
    int n = 5;
    int result = factorial(n);
    printf("%d! es igual a: %d\n", n, result);
    return 0;
}