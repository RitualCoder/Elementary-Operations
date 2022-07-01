/**
 * @file aux.h
 * @author Enzo Cornaggia (enzo.cornaggia@icloud.com)
 * @brief Basic auxiliary functions for elementary operations
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022, Enzo Cornaggia
 *
 **/

#include "aux.h"

#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../op_struct/private.h"
#include "../op.h"

char *inverser(char *str){
    if (!str || ! *str)
        return str;
    int i = strlen(str) - 1, j = 0;
    char ch;
    while (i > j){
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

bool remove_char(char *s, int pos){
    int length = strlen(s);
    if (pos >= length){
        return false;
    } 
    for (int i = pos; i < length; i++){
        s[i] = s[i + 1];
    }
    return true;
}

void op_delete(op operation){
    assert(operation);
    if (operation->num1 != NULL){
        free(operation->num1);
    }
    if (operation->num2 != NULL){
        free(operation->num2);
    }
    if (operation->result != NULL){
        free(operation->result);
    }
    if (operation != NULL){
        free(operation);
    }
    return;
}

op init(int length){
    assert(length);
    op operation = (op)malloc(sizeof(op));
    assert (operation);
    operation->num1 = malloc(length*sizeof(char));
    operation->num2 = malloc(length*sizeof(char));
    operation->result = malloc(length*sizeof(char));
    return operation;
}

bool check_str(char *str){
    int len = strlen(str);
    if (len > 1){
        if (str[0] == 48){
            printf("delete unnecessary 0's\n");
            return false;
        }
    }
    for (int i = 0; i < len; i++){
        if (str[i] < 48 || str[i]> 57){
            printf("Not an integer\n");
            return false;
        }
    }
    return true;
}
