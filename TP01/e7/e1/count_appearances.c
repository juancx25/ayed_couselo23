#include "../../../ADTs/charset.h"

int count_appearances(char* str, const char* symbols){
    charset* aux = charset_new();
    charset_setString(aux,symbols,true);
    int result = 0;
    while (*str != '\0'){
        char pepe = *str;
        result += charset_get(aux,*str);
        str++;
    }
    charset_free(aux);
    return result;
}