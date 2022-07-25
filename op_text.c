#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "library/op.h"
#include "library/aux.h"
#include "library/private.h"

void usage(){
    fprintf(stderr,"Usage : ./operation <operator>\n\n");
    fprintf(stderr, "add\n"
                    "sub\n"
                    "mul\n"
                    "div\n\n");
    fprintf(stderr, "La limite de caractère pour num1 et num2 est 100.\n");
}

int main(int argc, char *argv[]){
    // if there is not command
    if (argc != 2 || strcmp(argv[1], "usage") == 0){
        usage();
        return 0;
    }

    char a[100];
    char b[100];
    op var = init_(1000);
    printf("Veuillez saisir le premier nombre : ");
    scanf("%s", a);
    printf("Veuillez saisir le deuxième nombre : ");
    scanf("%s", b);
    printf("\n");
    if (check_str(a) && check_str(b)){
        if (strcmp(argv[1], "add") == 0){
            addition(var, a, b);
            op_delete(var);
        }
        else if (strcmp(argv[1], "sub") == 0){
            substraction(var, a, b);
            op_delete(var);
        }
        else if (strcmp(argv[1], "mul") == 0){
            multiplication(var, a, b, false);
            op_delete(var);
        }
        else if (strcmp(argv[1], "div") == 0){
            division(var, a, atoi(b));
            op_delete(var);
        }
        else if (strcmp(argv[1], "pow") == 0){
            pow_(var, a, atoi(b));
            op_delete(var);
        }
        return 1;
    }
    else {
        printf("Please select a valid integer\n");
        return 0;
    }
    
    // if the user type a wrong command
    usage();
    op_delete(var);
    return 0;
}