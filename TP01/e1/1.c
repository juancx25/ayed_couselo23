#include <stdlib.h>
#include <stdio.h>

int main(){
    const char* symbols = ".,;?!";
    char* phrase = "This, is a phrase; whose main purpose is to count punctuation signs. Is it well done? We will see!";

    int r = count_appearances(phrase,symbols);

    printf("The result is: %d\n",r);
    return 0;
}