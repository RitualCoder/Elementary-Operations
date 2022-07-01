#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "beta.h"
#include "aux.h"
#include "private.h"


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
    var->num1 = a;
    var->num2 = b;

    int len1 = strlen(var->num1);
    int len2 = strlen(var->num2);

    // check si la valeur de str2 > str1
    int superior = 0;
    if (len1 == len2){
        for (int i = 0; i < len1; i++){
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
    if (len1 <= len2 || superior == 1){
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
    if (inverse){
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
    static char quotient[500];
    long temp = 0;
    int i = 0, j = 0;

    while(dividend[i]){
        temp = temp * 10 + (dividend[i] - '0');
        if(temp < divisor){
            quotient[j++] = '0';
        }
        else{
            quotient[j++] = (temp / divisor) + '0';
            temp = temp % divisor;
        }
        i++;
    }
    
    // Traitement des "0" en trop
    inverser(quotient);
    i = strlen(quotient) - 1;
    while (quotient[i] == '0' && i != 0){
        remove_char(quotient, i);
        i--;
    }
    inverser(quotient);

    quotient[j] = '\0';
    printf("%s / %ld = %s\n", dividend, divisor, quotient);
    return quotient;
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
    char num1[50];
    if (argc != 2 || strcmp(argv[1], "usage") == 0){
        usage();
        return 0;
    }
    else if (strcmp(argv[1], "add") == 0){
        op var = init(100);
        printf("Veuillez saisir le premier nombre : ");
        scanf("%s", var->num1);
        printf("Veuillez saisir le deuxième nombre : ");
        scanf("%s", var->num2);
        printf("\n");
        addition(var, var->num1, var->num2);
        op_delete(var);
        return 1;
    }
    else if (strcmp(argv[1], "sub") == 0){
        op var = init(100);
        printf("Veuillez saisir le premier nombre : ");
        scanf("%s", var->num1);
        printf("Veuillez saisir le deuxième nombre : ");
        scanf("%s", var->num2);
        printf("\n");
        substraction(var, var->num1, var->num2);
        op_delete(var);
        return 1;
    }
    else if (strcmp(argv[1], "mul") == 0){
        op var = init(100);
        printf("Veuillez saisir le premier nombre : ");
        scanf("%s", var->num1);
        printf("Veuillez saisir le deuxième nombre : ");
        scanf("%s", var->num2);
        printf("\n");
        multiplication(var, var->num1, var->num2);
        op_delete(var);
        return 1;
    }
    else if (strcmp(argv[1], "div") == 0){
        long int num;
        printf("Veuillez saisir le premier nombre : ");
        scanf("%s", num1);
        printf("Veuillez saisir le deuxième nombre : ");
        scanf("%ld", &num);
        printf("\n");
        //division(num1, num);
        return 1;
    }
    usage();
    return 0;
}