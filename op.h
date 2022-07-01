#ifndef __OP_H__
#define __OP_H__

/**
 * @brief Standard unsigned integer type.
 **/
typedef unsigned int uint;

/**
 * @brief Sum of 2 strings numbers
 * @param num1 the first string number
 * @param num2 the second string number
 * @return the sum in a string
 **/
char* addition(char* num1, char* num2);


/**
 * @brief difference between 2 strings numbers
 * @param num1 the first string number
 * @param num2 the second string number
 * @return the difference in a string
 **/
char* substraction(char* num1, char* num2);

/**
 * @brief Product of 2 strings numbers
 * @param num1 the first string number
 * @param num2 the second string number
 * @return the product in a string
 **/
char* multiplication(char* num1, char* num2);

/**
 * @brief Quotient of 2 strings numbers
 * @param num1 the first string number
 * @param num2 the second string number
 * @return The quotient in a string
 **/
char* division(char* num1, long num2);

#endif