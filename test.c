#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "op.h"
#include "aux_func/aux.h"
#include "op_struct/private.h"



bool test_div(op var){
    bool check = true;
    if (var->result == NULL){
        check = false;
        return check;
    }
    var->result = division(var, "4", 2);
    if (strcmp(var->result,"2") != 0){
        check = false;
    }
    return check;
}

void usage(void){
    fprintf(stderr, "Usage : test_operator <testname>\n");
    fprintf(stderr,
            "division\n");
}

int main(int argc, char** argv){
    if (argc != 1) {
        usage();
        return EXIT_FAILURE;
    }
    op var = init_(100);
    bool ok = false;

    // Exécute la fonction que l'utilisateur a spécifié en argument
    //if (strcmp("division", argv[1]) == 0) {
    ok = test_div(var);
    // }
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