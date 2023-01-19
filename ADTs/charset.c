#include "charset.h"

charset* charset_new(){
    return (charset*)calloc(1,sizeof(charset));
}

void charset_free(charset* chset){
    free(chset);
}

uint8_t charset_get(charset* chset, char ch){
    return chset->_set[ch];
}

bool charset_set(charset* chset, char ch, bool value){
    bool result = false;
    if (ch < CHARSET_SIZE){
        chset->_set[ch] = value;
        result = true;
    }
    return result;
}

bool charset_setString(charset* chset, char* str, bool value){
    bool result = true;
    int strSize = strlen(str);
    for (int i=0;i<strSize;i++){
        result &= charset_set(chset,str[i],value);
    }
    return result;
}

bool charset_setRange(charset* chset, unsigned int from, unsigned int to, bool value){
    bool result = true;
    if (to > CHARSET_SIZE){
        to = CHARSET_SIZE;
        result = false;
    }
    for (int i=from;i<to;i++){
        chset->_set[i] = value;
    }
    return result;
}

void charset_printAsChar(charset* chset){
    for (int i=0;i<CHARSET_SIZE;i++){
        if (chset->_set[i]) printf("%c ",i);
    }
    printf("\n");
}