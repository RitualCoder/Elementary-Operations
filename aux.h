#ifndef __AUX_H__
#define __AUX_H__
#include <string.h>
#include <stdbool.h>
#include "op.h"

/**
 * @brief Reverse a string
 * @param str the string number
 * @return the reverse string
 **/
char *inverser(char *str);

/**
 * @brief Remove a character in a string at a position
 * @param s the string
 * @param pos the character position
 * @return the new string
 **/
bool remove_char(char *s, int pos);

/**
 * @brief Free op struct
 * @param operation The op struct to delete
 * @return void
 **/
void op_delete(op operation);

/**
 * @brief Initialize the new struct
 * @param length The length of the string
 * @return The new struct
 **/
op init(int length);


#endif