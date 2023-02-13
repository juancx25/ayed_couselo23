#include "../../ADTs/stack/stack_dynamic.h"
//CHANGE t_elem TO CHAR
#include "../../ADTs/queue/queue_dynamic.h"
//CHANGE t_elem TO CHAR

#include <string.h>
//not working properly
char* makePalindrome(char* origin){
    int len = strlen(origin);
    char* palindrome = (char*)malloc(sizeof(char)*len);
    stack* s = stack_new(len);
    queue* q = queue_new(len);
    int i = 0;
    while (!queue_isfull(q)){
        char ch = origin[i++];
        if (ch != 32) push(s, ch);
        enqueue(q, ch);
    }
    i = 0;
    while (!stack_isempty(s)){
        if(dequeue(q) == 32){
            palindrome[i++] = 32;
        }
        palindrome[i++] = pop(s);
    }
    palindrome[i] = '\0';
    stack_free(s);
    queue_free(q);
    return palindrome;
}

int main(){
    char* phrase = "a nut for a jar of tuna";
    char* palindrome = makePalindrome(phrase);
    printf("Phrase: %s\nPalindrome: %s\n", phrase, palindrome);

    //free(palindrome);
    return 0;
}