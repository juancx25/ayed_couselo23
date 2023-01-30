#include "../../ADTs/charset.h"

/**
 * The following is a test program of the charset ADT.
 */
int main(){

    charset* test = charset_new();

    //Setting J to true
    charset_set(test,'J',true);
    charset_printAsChar(test);

    //Setting string to true
    charset_setString(test,"Testing...",true);
    charset_printAsChar(test);

    //Setting J to
    charset_set(test,'J',false);
    char* isContained = charset_get(test,'J') ? "yes" : "no";
    printf("Is J in the charset? %s\n",isContained);
    
    //Setting all values to true
    charset_setRange(test,0,CHARSET_SIZE,true);
    charset_printAsChar(test);

    //Resetting everything to false
    charset_setRange(test,0,CHARSET_SIZE,false);
    charset_printAsChar(test);

    //Setting string to true
    charset_setString(test,"Again!",true);
    charset_printAsChar(test);

    charset_free(test);
    return 0;
}