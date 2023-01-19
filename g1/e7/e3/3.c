#include "../../../ADTs/charset.h"

int validate_username(const char* username){
    
}

int main(){
    char* username_1 = "Ju4n_";
    char* username_2 = "Ju4n";
    char* re_1 = validate_username(username_1) ? "valid" : "invalid";
    char* re_2 = validate_username(username_2) ? "valid" : "invalid";

    printf("%s: %s, %s: %s\n ",username_1, re_1, username_2, re_2);
}