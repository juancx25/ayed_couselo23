#include <stdlib.h>
#include <stdio.h>

int validate_username(const char* username){
    int hasUppercase = 0,
        hasLowercase = 0,
        hasNumbers = 0,
        hasSpecialCharacter = 0;

    int i = 0;
    while (username[i] != '\0'){
        char value = username[i];
        if (value > 64 && value < 91) hasUppercase = 1;
        else if (value > 96 && value < 123) hasLowercase = 1;
        else if (value > 47 && value < 58) hasNumbers = 1;
        else if (value == 95 || value == 45) hasSpecialCharacter = 1;
        i++;
    }
    return hasUppercase && hasLowercase && hasNumbers && hasSpecialCharacter;
}

int main(){
    char* username_1 = "Ju4n_";
    char* username_2 = "Ju4n";
    char* re_1 = validate_username(username_1) ? "valid" : "invalid";
    char* re_2 = validate_username(username_2) ? "valid" : "invalid";

    printf("%s: %s, %s: %s\n ",username_1, re_1, username_2, re_2);
}