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

char *int_to_char(long num, char *array){
    long temp = num;
    int i = 0;
    while (temp > 0){
        array[i] = (temp%10) + '0';
        temp = temp/10;
        i++;
    }
    array[i] = '\0';
    inverser(array);
    return array;
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
    int i;
    if (pos >= length){
        return false;
    } 
    for (i = pos; i < length; i++){
        s[i] = s[i + 1];
    }
    return true;
}

void delete_string(op var, uint str_len1, uint str_len2, uint str_len3){
    for (int i = 0; i < str_len1; i++){
        remove_char(var->num1, 0);
    }
    for (int i = 0; i < str_len2; i++){
        remove_char(var->num2, 0);
    }
}

void insert_char(op var, int pos, uint str_len){
    char temp[20];
    int i; // index for temp
    int j; // index for the numb to insert
    int k = pos; // index for var->str
    for (i = 0; i < pos; i++){
        temp[i] = var->str[i];
    }
    for (j = 0; j < str_len; i++, j++){
        temp[i] = var->result[j];
    }
    for (; var->str[k] != '\0'; k++){
        temp[i] = var->str[k];
        i++;
    }
    temp[i++] = '\0';
    strcpy(var->str, temp);
}

void op_delete(op operation){ 
    assert(operation);
    assert(operation->num1);
    assert(operation->num2);
    assert(operation->result);
    free(operation->str);
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
    operation->str = malloc(length*sizeof(char));
    assert(operation->str);
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

bool check_str2(char *str){
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

bool is_operator(char str){
    if (str == 42 || str == 43 || str == 45 || str == 47 || str == 94){
        return true;
    }
    return false;
}

bool check_str(char *str){
    int len = strlen(str);
    int left_par = 0;
    int right_par = 0;
    for (int i = 0; i < len; i++){

        // Check all char possible in the str
        if ((str[i] < 48 || str[i] > 57) && (!is_operator(str[i]) && (str[i] != 40) && (str[i] != 41))){
            return false;
        }

        // Check first char if it's not an operator or a right par
        if (i == 0){
            if (str[i] == 41 || is_operator(str[i])){
                return false;
            }
        }

        if (is_operator(str[i])){
            // Check the next char after an operator
            if (str[i + 1] < 48 || str[i + 1] > 57 || str[i + 1] == 41 || is_operator(str[i + 1])){
                return false;
            }
        }

        // Check if there is "()"
        if (str[i] == 40){
            left_par ++;
            if (str[i + 1] == 41 || is_operator(str[i + 1])){
                return false;
            }
        }

        // Check parenthese
        if (str[i] == 41){
            right_par++;

            // Check if there is ")" before "("
            if (left_par < 1){
                return false;
            }

            // Check if there is more ")" than "("
            if (left_par < right_par){
                return false;
            }
        }
    }

    if (left_par != right_par){
        return false;
    }
    return true;
}

bool check_if_there_is_operator(char *str){
    uint len = strlen(str);

    for (int i = 0; i < len; i++){
        if (is_operator(str[i])){
            return true;
        }
    }
    return false;
}


// Delete the 2 numbers after an operation has been made in the character 
// string in order to avoid redoing the calculation
void delete_char_after_operation(op var, uint rank, uint str_len){
    for (int i = 0; i < str_len; i++){
        remove_char(var->str, rank);
    }
}

void char_calculation(op var){
    uint len = strlen(var->str);
    int j = 0;
    int i = 0;
    int countnum1 = 0;
    int countnum2 = 0;

    while(check_if_there_is_operator(var->str)){
        while (var->str[i] != '\0'){ 
            
            // FOR POW
            if (var->str[i] == 94){
                j = i;
                // copy first numb in op->num1
                while (j > 0 && !is_operator(var->str[j - 1])){
                    j--;
                    var->num1[countnum1] = var->str[j];
                    countnum1++;
                }
                inverser(var->num1);
                j = i;

                // copy second numb in op->num2
                while(j < len && !is_operator(var->str[j + 1])){
                    j++;
                    var->num2[countnum2] = var->str[j];
                    countnum2++;
                }
                // printf("%s (%d) et %s (%d)\n", var->num1, countnum1, var->num2, countnum2);
                pow_(var);
                remove_char(var->str, i);
                delete_char_after_operation(var, i - countnum1, countnum1 + countnum2);
                var->str[len - countnum1 - countnum2] = '\0';
                // printf("After delete %s\n", var->str);
                insert_char(var, i - countnum1, strlen(var->result));
                printf("%s\n", var->str);
                delete_string(var, countnum1, countnum2, strlen(var->result));
                countnum1 = 0;
                countnum2 = 0;
                i=0;
            }
            i++;
        }
        i=0;
        
        while (var->str[i] != '\0'){ 
            
            // FOR MULTIPLICATION and DIVISION
            if (var->str[i] == 42 || var->str[i] == 47){
                len = strlen(var->str);
                j = i;
                // copy first numb in op->num1
                while (j > 0 && !is_operator(var->str[j - 1])){
                    j--;
                    var->num1[countnum1] = var->str[j];
                    countnum1++;
                }
                inverser(var->num1);
                j = i;

                // copy second numb in op->num2
                while(j < len && !is_operator(var->str[j + 1])){
                    j++;
                    var->num2[countnum2] = var->str[j];
                    countnum2++;
                }
                
                // Put the result in var->result
                if (var->str[i] == 42) {
                    multiplication(var, var->num1, var->num2, true);
                }
                else {
                    division(var, var->num1, atoi(var->num2));
                }

                // Delete the operator between num1 and num2
                remove_char(var->str, i);

                // Delete the operation to do in the string
                delete_char_after_operation(var, i - countnum1, countnum1 + countnum2);

                // Terminate correctly the string
                var->str[len - countnum1 - countnum2] = '\0';
                // printf("After delete %s\n", var->str);
                insert_char(var, i - countnum1, strlen(var->result));
                printf("%s\n", var->str);
                delete_string(var, countnum1, countnum2, strlen(var->result));
                // printf("test2 : %s\n", var->str);
                countnum1 = 0;
                countnum2 = 0;
                i=0;
            }
            i++;
        }
        i = 0;

        while (var->str[i] != '\0'){ 
            
            // FOR ADDITION and SUBASTRACTION
            if (var->str[i] == 43 || var->str[i] == 45){
                len = strlen(var->str);
                j = i;
                // copy first numb in op->num1
                while (j > 0 && !is_operator(var->str[j - 1])){
                    j--;
                    var->num1[countnum1] = var->str[j];
                    countnum1++;
                }
                inverser(var->num1);
                j = i;

                // copy second numb in op->num2
                while(j < len && !is_operator(var->str[j + 1])){
                    j++;
                    var->num2[countnum2] = var->str[j];
                    countnum2++;
                }
                
                // Put the result in var->result
                if (var->str[i] == 43) {
                    addition(var);
                }
                else {
                    substraction(var);
                }

                // Delete the operator between num1 and num2
                remove_char(var->str, i);

                // Delete the operation to do in the string
                delete_char_after_operation(var, i - countnum1, countnum1 + countnum2);

                // Terminate correctly the string
                var->str[len - countnum1 - countnum2] = '\0';
                // printf("After delete %s\n", var->str);
                insert_char(var, i - countnum1, strlen(var->result));
                printf("%s\n", var->str);
                delete_string(var, countnum1, countnum2, strlen(var->result));
                countnum1 = 0;
                countnum2 = 0;
                i=0;
            }
            i++;
        }
    }
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

void print_result(op var, char *a, char *b, char operator){
    char temp_s[100];
    strcpy(temp_s, var->result);
    temp_s[10] = '\0';
    float temp = atol(temp_s);
    if (strlen(var->result) > 8){
        printf("%s %c %s = %.2e\n", a, operator, b, temp);
    }
    else {
        printf("%s %c %s = %s\n", a, operator, b, var->result);
    }
}
