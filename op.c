#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "op.h"
#include "aux_func/aux.h"
#include "op_struct/private.h"


char *addition(op var, char *a, char *b){
    var->num1 = a;
    var->num2 = b;

    int len1 = strlen(var->num1);
    int len2 = strlen(var->num2);
    if (len1 > len2){
        inverser(var->num2);
        for (int i = strlen(var->num2); i < strlen(var->num1); i++){
            strcat(var->num2, "0");
        }
        inverser(var->num2);
    }
    if (len1 < len2) {
        inverser(var->num1);
        for (int i = len1; i < len2; i++){
            strcat(var->num1, "0");
        }
        inverser(var->num1);
    }
    int result, retenue = 0;
    for (int i = strlen(var->num1) - 1; i >= 0; i--){
        result = (var->num1[i] - '0') + (var->num2[i] - '0') + retenue;
        if (result >= 10){
            retenue = result/10;
            var->result[i] = (result % 10 + '0');
        }
        else{
            var->result[i] = (result + '0');
            retenue = 0;
        }
        if (i == 0 && retenue != 0){
            inverser(var->result);
            var->result[strlen(var->result)] = (retenue + '0');
            inverser(var->result);
        }
    }
    printf("%s + %s = %s\n", a, b, var->result);
    return var->result;
}

char * substraction(op var, char* a, char* b){
    int len1 = strlen(var->num1);
    int len2 = strlen(var->num2);

    // check si la valeur de num2 > num1
    int superior = 0;
    if (len1 <= len2){
        for (int i = len1 - 1; i >= 0; i--){
            if (var->num1[i] - '0' < var->num2[i] - '0'){
                superior = 1;
                break;
            }
        }
    }
    
    // Si le premier nb est inférieur à celui du deuxième :
    // Inversement des chaines de caractères
    char* temp;
    bool inverse = false;
    if (len1 <= len2 && superior == 1){
        temp = var->num2;
        var->num2 = var->num1;
        var->num1 = temp;
        inverse = true;
        len1 = strlen(var->num1);
        len2 = strlen(var->num2);
    }
    
    // Comblage de "0" sur le nb possèdant le moins de chiffre
    if (len1 > len2){
        inverser(var->num2);
        for (int i = strlen(var->num2); i < strlen(var->num1); i++){
            strcat(var->num2, "0");
        }
        inverser(var->num2);
    }
    if (len1 < len2) {
        inverser(var->num1);
        for (int i = len1; i < len2; i++){
            strcat(var->num1, "0");
        }
        inverser(var->num1);
    }

    // Opération
    int retenu = 0, result;
    for (int i = strlen(var->num1) - 1; i >= 0; i--){
        if (var->num1[i] - '0' >= var->num2[i] - '0' + retenu){
            result = (var->num1[i] - '0') - (var->num2[i] - '0' + retenu);
            retenu = 0;
            var->result[i] = (result + '0');
        }
        else {
            result = (var->num1[i] - '0' + 10) - (var->num2[i] - '0' + retenu);
            retenu = 1;
            var->result[i] = (result + '0');
        }
    }

    // Traitement des "0" en trop
    inverser(var->result);
    int i = strlen(var->result) - 1;
    while (var->result[i] == '0' && i != 0){
        remove_char(var->result, i);
        i--;
    }
    inverser(var->result);

    // Si le resultat est négatif
    if (inverse && strcmp(var->result, "0") != 0){
        inverser(var->result);
        strcat(var->result, "-");
        inverser(var->result);
    }

    printf("%s - %s = %s\n", a, b, var->result);
    return var->result;
}



char * multiplication(op var, char *a, char *b){
    var->num1 = a;
    var->num2 = b;

    // Operation
    int mul, i, j;
    memset(var->result, '0', strlen(var->num1) + strlen(var->num2));
    var->result[strlen(var->num1) + strlen(var->num2)] = 0;
    for (i = strlen(var->num1) - 1; i >= 0; i--){
        for (j = strlen(var->num2) - 1; j >= 0; j--){
            mul = (var->num1[i] - '0') * (var->num2[j] - '0');
            var->result[i + j] += ((var->result[i + j + 1] + mul - '0') / 10);
            var->result[i + j + 1] = ((var->result[i + j + 1] + mul - '0') % 10) + '0';
        }
    }

    // Traitement des "0" en trop
    inverser(var->result);
    i = strlen(var->result) - 1;
    while (var->result[i] == '0' && i != 0){
        remove_char(var->result, i);
        i--;
    }
    inverser(var->result);

    printf("%s * %s = %s\n",a , b, var->result);
    return var->result;
}

char *division(op var, char *dividend,long divisor){
    long temp = 0;
    int i = 0, j = 0;

    while(var->num1[i]){
        temp = temp * 10 + (var->num1[i] - '0');
        if(temp < divisor){
            var->result[j++] = '0';
        }
        else{
            var->result[j++] = (temp / divisor) + '0';
            temp = temp % divisor;
        }
        i++;
    }
    
    // Traitement des "0" en trop
    inverser(var->result);
    i = strlen(var->result) - 1;
    while (var->result[i] == '0' && i != 0){
        remove_char(var->result, i);
        i--;
    }
    inverser(var->result);

    var->result[j] = '\0';
    printf("%s / %ld = %s\n", dividend, divisor, var->result);
    return var->result;
}

void usage(){
    fprintf(stderr,"Usage : ./operation <operator>\n\n");
    fprintf(stderr, "add\n"
                    "sub\n"
                    "mul\n"
                    "div\n\n");
    fprintf(stderr, "La limite de caractère pour num1 et num2 est 50.\n");
}


int main(int argc, char *argv[]){
    if (argc != 2 || strcmp(argv[1], "usage") == 0){
        usage();
        return 0;
    }
    op var = init(100);
    printf("Veuillez saisir le premier nombre : ");
    scanf("%s", var->num1);
    printf("Veuillez saisir le deuxième nombre : ");
    scanf("%s",var->num2);
    printf("\n");
    
    if (strcmp(argv[1], "add") == 0){
        addition(var, var->num1, var->num2);
        return 1;
    }
    else if (strcmp(argv[1], "sub") == 0){
        substraction(var, var->num1, var->num2);
        op_delete(var);
        return 1;
    }
    else if (strcmp(argv[1], "mul") == 0){
        multiplication(var, var->num1, var->num2);
        op_delete(var);
        return 1;
    }
    else if (strcmp(argv[1], "div") == 0){
        division(var, var->num1, atoi(var->num2));
        op_delete(var);
        return 1;
    }
    usage();
    op_delete(var);
    return 0;
}