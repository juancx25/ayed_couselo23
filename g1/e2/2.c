#include <stdlib.h>
#include <stdio.h>

#include "../e1/count_appearances.c"

int main(){
    const char* symbols = "+-/*";
    char* operation = "(14+3)/7-3*4+(2/3)+5";

    int r = count_appearances(operation,symbols);
    printf("El resultado es: %d\n",r);
    return 0;
}