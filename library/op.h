/**
 * @file op.h
 * @author Enzo Cornaggia (enzo.cornaggia@icloud.com)
 * @brief Basic functions of elementary operations with strings
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 **/

#ifndef __OP_H__
#define __OP_H__

#include <stdbool.h>

/**
 * @brief The structure pointer that stores the operation state.
 **/
typedef struct op_s* op;

/**
 * @brief Standard unsigned integer type.
 **/
typedef unsigned int uint;

/**
 * @brief Sum of 2 strings numbers
 * @param num1 The first string number
 * @param num2 The second string number
 * @return The sum in a string
 **/
char *addition(op var);


/**
 * @brief Difference between 2 strings numbers
 * @param num1 The first string number
 * @param num2 The second string number
 * @return The difference in a string
 **/
char *substraction(op var);

/**
 * @brief Product of 2 strings numbers
 * @param num1 The first string number
 * @param num2 The second string number
 * @return The product in a string
 **/
char *multiplication(op var, char* num1, char* num2, bool auxi);

/**
 * @brief Quotient of 2 strings numbers
 * @param num1 The first string number
 * @param num2 The second string number
 * @return The quotient in a string
 **/
char *division(op var, char* num1, long num2);


/**
 * @brief Pow with a string and a long
 * @param num1 The first string number
 * @param pow1 The second long integer
 * @return The pow in a string
**/
char *pow_(op var);

#endif
