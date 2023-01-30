#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool _int_isAscending(char* value){
    if (value[1] == '\0') return true;
    if (value[0] > value[1]) return false;
    if (!_int_isAscending(value+1)) return false;
    return true;
}

bool int_isAscending(int value){
    int digits = (int)((ceil(log10(value))+1)*sizeof(char));
    char str[digits];
    sprintf(str, "%d", value);
    return _int_isAscending(str);
}

int main(){
    int value = 5678;
    bool result = int_isAscending(value);
    return 0;
}