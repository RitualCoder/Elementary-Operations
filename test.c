#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "library/op.h"
#include "library/aux.h"
#include "library/private.h"

bool test_add(op var){
    bool check = true;
    if (var->result == NULL){
        check = false;
        return check;
    }
    addition(var, "4", "4");
    if (strcmp(var->result,"8") != 0){
        printf("ok");
        check = false;
    }
    addition(var, "0", "0");
    if (strcmp(var->result,"0") != 0){
        check = false;
    }
    addition(var, "294209540245", "2785275427555508475");
    if (strcmp(var->result,"2785275721765048720") != 0){
        check = false;
    }
    return check;
}

bool test_sub(op var){
    bool check = true;
    if (var->result == NULL){
        check = false;
        return check;
    }
    substraction(var, "4", "4");
    if (strcmp(var->result,"0") != 0){
        check = false;
    }
    substraction(var, "3", "4");
    if (strcmp(var->result,"-1") != 0){
        check = false;
    }
    substraction(var, "0", "4786");
    if (strcmp(var->result,"-4786") != 0){
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
    multiplication(var, "0", "0", true);
    if (strcmp(var->result,"0") != 0){
        check = false;
    }
    multiplication(var, "28745845", "237254728541540", true);
    if (strcmp(var->result,"6820087652172184901300") != 0){
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
    division(var, "0", 1);
    if (strcmp(var->result,"0") != 0){
        check = false;
    }
    division(var, "99", 2);
    if (strcmp(var->result,"49") != 0){
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
    if (strcmp(var->result,"16") != 0 && !check_str(var->result)){
        check = false;
    }
    pow_(var, "0", 0);
    if (strcmp(var->result,"1") != 0 && !check_str(var->result)){
        check = false;
    }
    pow_(var, "42", 5);
    if (strcmp(var->result,"130691232") != 0 && !check_str(var->result)){
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