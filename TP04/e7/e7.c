#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* _invert_word(char* word, char* new_word){
    if (*word == '\0') return new_word;
    new_word[strlen(word)-1] = word[0];
    return _invert_word(word+1, new_word);
}

char* invert_word(char* word){
    int len = strlen(word) + 1;
    char* aux = (char*)malloc(sizeof(char)*len);
    memset(aux, 0, len);
    return _invert_word(word, aux);
}

int main(){
    char* word = "lamina";
    char* result = invert_word(word);
    printf("%s => %s\n", word, result);
    free(result);
    return 0;
}