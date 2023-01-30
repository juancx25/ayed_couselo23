#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int num;
    int den;
} fraction;

/**
 * @brief Creates a new fraction
 * 
 * @return fraction*
 */
fraction* fraction_new();

/**
 * @brief Initializes a new fraction with numerator and denominator
 * 
 * @param num Numerator
 * @param den Denominator
 * @return fraction* 
 */
fraction* fraction_init(int num, int den);

/**
 * @brief Frees the memory allocated for the sent fraction
 * 
 */
void fraction_free(fraction* f);

/**
 * @brief Returns the numerator
 * 
 * @return int Result
 */
int fraction_getNum(const fraction* f);

/**
 * @brief Returns the denominator
 * 
 * @return int Result
 */
int fraction_getDen(const fraction* f);

/**
 * @brief Sets the numerator
 * 
 * @param num Numerator
 */
void fraction_setNum(fraction* f, int num);

/**
 * @brief Sets the denominator
 * 
 * @param den Denominator
 * @return true: Success
 * @return false: Couldn't add
 */
bool fraction_setDen(fraction* f, int den);

/**
 * @brief Returns the fraction real value
 * 
 * @return double Result
 */
double fraction_getValue(const fraction* f);

/**
 * @brief Prints a fraction on stdout
 * 
 */
void fraction_print(const fraction* f);

/**
 * @brief Simplifies the sent fraction (if possible)
 * 
 */
void fraction_simplify(fraction* f);

/**
 * @brief Compares two fractions
 * 
 * @return int 1(r1>r2) | -1(r1<r2) | 0(r1==r2)
 */
int fraction_compare(const fraction* f1, const fraction* f2);

/**
 * @brief Calculates the sum between two fractions
 * 
 * @return fraction* 
 */
fraction* fraction_sum(const fraction* f1, const fraction* f2);

/**
 * @brief Calculates subtraction between two fractions
 * 
 * @return fraction* 
 */
fraction* fraction_subtract(const fraction* f1, const fraction* f2);

/**
 * @brief Calculates multiplication between two fractions
 * 
 * @return fraction* 
 */
fraction* fraction_multiply(const fraction* f1, const fraction* f2);

/**
 * @brief Calculates division between two fractions
 * 
 * @return fraction* 
 */
fraction* fraction_divide(const fraction* f1, const fraction* f2);

/**
 * @brief Gets the Higest Common Factor (Español: Máximo Común Divisor, MCD)
 *        from two integers
 * 
 * @return int HCF
 */
int _getHCF(int a, int b);

/**
 * @brief Gets the Least Common Multiple (Español: Mínimo Común Múltiplo, MCM)
 *        from two integers
 * 
 * @return int LCM
 */
int _getLCM(int a, int b);

// This line allows VS Code to link the header to the implementation. Should be removed if it doesn't link correctly
#include "fraction.c"

#endif