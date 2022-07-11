/**
 * @file aux.h
 * @author Enzo Cornaggia (enzo.cornaggia@icloud.com)
 * @brief Basic auxiliary functions for elementary operations
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 **/

#ifndef __AUX_H__
#define __AUX_H__
#include <string.h>
#include <stdbool.h>
#include "../op.h"

/**
 * @brief Reverse a string
 * @param s the string number
 * @return the reverse string
 **/
void inverser(char *s);

/**
 * @brief Reverse an integer
 * @param a The integer
 * @return The reverse integer
 **/
int inverser_numb(int a);

/**
 * @brief Give the length of a string
 * @param s The string
 * @return The length
 **/
int string_length(char *str);

/**
 * @brief Remove a character in a string at a position
 * @param s The string
 * @param pos The character position
 * @return The new string
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
op init_(int length);

/**
 * @brief Check if the string is valide integer
 * @param length The string
 * @return A boolean
 **/
bool check_str(char *str);

/**
 * @brief Transform an int to string
 * @param x The integer
 * @param str The string
 * @return The string
 **/
char *int_string(int x, char *str);

/**
 * @brief Transform a string number in a scientific form
 * @param a The first string
 * @param b The second string
 * @param var The op struct to modificate
 * @return Void
 **/
void print_result(op var, char *a, char *b);

#endif