#ifndef CHARSET_H_INCLUDED
#define CHARSET_H_INCLUDED

#define CHARSET_SIZE 256
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <inttypes.h>
#include <stdbool.h>

typedef struct{
    uint8_t _set[CHARSET_SIZE];
} charset;

/**
 * @brief Creates a new Charset object.
 * 
 * @return charset* (pointer to itself).
 */
charset* charset_new();

/**
 * @brief Frees memory assigned to the sent Charset
 * 
 * @param chset Charset to free
 */
void charset_free(charset* chset);

/**
 * @brief Returns the charset status of the sent character (set or not set)
 * 
 * @param chset Charset
 * @param ch Character to check
 * @return uint8_t 1 if set, 0 if not set
 */
uint8_t charset_get(charset* chset, char ch);

/**
 * @brief Sets the character position to the value given
 * 
 * @param chset Charset
 * @param ch Character 
 * @param value New status
 * @return [true] Changes made successfully
 * @return [false] Out of range: no changes made.
 */
bool charset_set(charset* chset, char ch, bool value);

/**
 * @brief Sets the charset characters given in a string
 * 
 * @param chset Charset
 * @param str String of characters to be set or unset
 * @param value true (set) or false (not set)
 * @return [true] Changes made successfully
 * @return [false] Out of range: set in-range characters only.
 */
bool charset_setString(charset* chset, char* str, bool value);

/**
 * @brief Sets charset characters in a range
 * 
 * @param chset Charset
 * @param from Start
 * @param to End
 * @param value true (set) or false (not set)
 * @return [true] Changes made successfully
 * @return [false] Out of range: limit set to max charset size.
 */
bool charset_setRange(charset* chset, unsigned int from, unsigned int to, bool value);

/**
 * @brief Prints the charset with the caracters corresponding to each position.
 * 
 * @param chset Charset
 */
void charset_printAsChar(charset* chset);

// This line allows VS Code to link the header to the implementation. Should be removed if it doesn't link correctly
#include "charset.c"

#endif