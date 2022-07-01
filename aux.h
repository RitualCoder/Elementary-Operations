#ifndef __AUX_H__
#define __AUX_H__
#include <string.h>
#include <stdbool.h>


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


#endif