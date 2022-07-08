#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "op.h"
#include "aux_func/aux.h"
#include "op_struct/private.h"

bool test_add(op var){
    bool check = true;
    if (var->result == NULL){
        check = false;
        return check;
    }
    char *num1 = "4";
    char *num2 = "4";
    addition(var, num1, num2);
    if (strcmp(var->result,"8") != 0){
        check = false;
    }
    /* addition(var, "0", "0");
    if (strcmp(var->result,"0") != 0){
        check = false;
    } */
    return check;
}

bool test_sub(op var){
    bool check = true;
    if (var->result == NULL){
        check = false;
        return check;
    }
    char *num1 = "4";
    char *num2 = "4";
    substraction(var, num1, num2);
    if (strcmp(var->result,"0") != 0){
        check = false;
    }
    return check;
}


bool test_mul(op var){
    bool check = true;
    if (var->result == NULL){
        check = false;
        return check;
    }
    multiplication(var, "4", "4", true);
    if (strcmp(var->result,"16") != 0){
        check = false;
    }
    return check;
}

bool test_div(op var){
    bool check = true;
    if (var->result == NULL){
        check = false;
        return check;
    }
    division(var, "4", 2);
    if (strcmp(var->result,"2") != 0){
        check = false;
    }
    return check;
}

bool test_pow(op var){
    bool check = true;
    if (var->result == NULL){
        check = false;
        return check;
    }
    pow_(var, "4", 2);
    if (strcmp(var->result,"16") != 0){
        check = false;
    }
    return check;
}

void usage(void){
    fprintf(stderr, "Usage : test_operator <testname>\n");
    fprintf(stderr,
            "add\n"
            "sub\n"
            "mul\n"
            "div\n");
}

int main(int argc, char** argv){
    if (argc != 2) {
        usage();
        return EXIT_FAILURE;
    }
    op var = init_(100);
    bool ok = false;

    // Exécute la fonction que l'utilisateur a spécifié en argument
    if (strcmp("add", argv[1]) == 0) {
        ok = test_add(var);
    }
    else if (strcmp("sub", argv[1]) == 0) {
        ok = test_sub(var);
    }
    else if (strcmp("mul", argv[1]) == 0) {
        ok = test_mul(var);
    }
    else if (strcmp("div", argv[1]) == 0) {
        ok = test_div(var);
    }
    else if (strcmp("pow", argv[1]) == 0) {
        ok = test_pow(var);
    }

    op_delete(var);
    if (ok) {
        fprintf(stderr, "Test [%s] finished : SUCCESS\n", argv[1]);
        return EXIT_SUCCESS;
    }
    else {
        fprintf(stderr, "Test [%s] finished : FAILURE\n", argv[1]);
        return EXIT_FAILURE;
    }
}