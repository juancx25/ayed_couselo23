#include <stdio.h>

void print_halfPiramid(unsigned int n){
    if (n == 0) return;
    print_halfPiramid(n-1);
    for (int i=n;i>0;i--){
        printf("%d  ",i);
    }
    printf("\n");
}

int main(){
    print_halfPiramid(5);
    return 0;
}