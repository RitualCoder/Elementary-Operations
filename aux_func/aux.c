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

void inverser(char *s){
    int length, c;
    char *begin, *end, temp;
    length = string_length(s);
    begin = s;
    end = s;
    for (c = 0; c < length - 1; c++){
        end++;
    }
    for (c = 0; c < length/2; c++) {        
        temp   = *end;
        *end   = *begin;
        *begin = temp;
        begin++;
        end--;
    }
}

int inverser_numb(int a){
    int NbrInverse = 0, nbr;
    while (nbr != 0){
        NbrInverse = NbrInverse * 10;
        NbrInverse = NbrInverse + nbr%10;
        nbr = nbr/10;
    }
    return NbrInverse;
}
 
int string_length(char *str){
    int count = 0;
    while( *(str + count) != '\0' ){
        count++;
    }
    return count;
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
    assert(operation->num1);
    assert(operation->num2);
    assert(operation->result);
    free(operation->num1);
    free(operation->num2);
    free(operation->result);
    free(operation->sresult);
    free(operation);
    return;
}

op init_(int length){
    assert(length);
    op operation = malloc(sizeof(struct op_s));
    assert (operation);
    operation->num1 = malloc(length*sizeof(char));
    assert(operation->num1);
    operation->num2 = malloc(length*sizeof(char));
    assert(operation->num2);
    operation->result = malloc(length*sizeof(char));
    assert(operation->result);
    operation->sresult = malloc(length*sizeof(char));
    assert(operation->sresult);
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
            printf("'%s' is not an integer\n", str);
            return false;
        }
    }
    return true;
}

char *int_string(int x, char *str){
    long long temp = x;
    int i = 0;
    while (temp != 0){
        str[i] = (temp%10 + '0');
        temp = temp/10;
        i++;
    }
    str[i+1] = '\0';
    inverser(str);
    return str;
}

void scientific_form(int pos, op var){
    int i;
    char array[100];
    long long count = 0, j = 0;
    for (i = 0; i < pos; i++, j++){
        if (i == 1){
            var->sresult[i] = ',';
            i++;
        }
        var->sresult[i] = var->result[j];
    }
    count = strlen(var->result) - 1;
    var->sresult[i+1] = '\0';
    strcat(var->sresult, " * 10^");
    strcat(var->sresult, int_string(count, array));
    strcat(var->sresult, "\0");
}
