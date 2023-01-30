#include <stdio.h>

int recursive_sum(int n){
    if (n == 0) return 0;
    return n + recursive_sum(n-1);
}

int main(){
    int n = 6;
    int result = recursive_sum(n);
    printf("The result of the sum is: %d\n",result);
    return 0;
}