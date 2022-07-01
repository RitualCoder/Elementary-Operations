#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#include "op.h"
#include "aux.h"
#include "private.h"


char * addition(char *a, char *b){
    char *sum = malloc(100 * sizeof(char));
    char *str1 = malloc(100 * sizeof(char));
    char *str2 = malloc(100 * sizeof(char));
    strcpy(str1, a);
    strcpy(str2, b);

    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if (len1 > len2){
        inverser(str2);
        for (int i = strlen(str2); i < strlen(str1); i++){
            strcat(str2, "0");
        }
        inverser(str2);
    }
    if (len1 < len2) {
        inverser(str1);
        for (int i = len1; i < len2; i++){
            strcat(str1, "0");
        }
        inverser(str1);
    }
    int result, retenue = 0;
    for (int i = strlen(str1) - 1; i >= 0; i--){
        result = (str1[i] - '0') + (str2[i] - '0') + retenue;
        if (result >= 10){
            retenue = result/10;
            sum[i] = (result % 10 + '0');
        }
        else{
            sum[i] = (result + '0');
            retenue = 0;
        }
        if (i == 0 && retenue != 0){
            inverser(sum);
            sum[strlen(sum)] = (retenue + '0');
            inverser(sum);
        }
    }
    printf("%s + %s = %s\n", a, b, sum);
    free(str1);
    free(str2);
    return sum;
}

char * substraction(char* a, char* b){
    char *sum = malloc(50 * sizeof(char));
    char *str1 = malloc(50 * sizeof(char));
    char *str2 = malloc(50 * sizeof(char));
    strcpy(str1, a);
    strcpy(str2, b);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // check si la valeur de str2 > str1
    int superior = 0;
    if (len1 == len2){
        for (int i = 0; i < len1; i++){
            if (str1[i] - '0' < str2[i] - '0'){
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
        temp = str2;
        str2 = str1;
        str1 = temp;
        inverse = true;
        len1 = strlen(str1);
        len2 = strlen(str2);
    }
    
    // Comblage de "0" sur le nb possèdant le moins de chiffre
    if (len1 > len2){
        inverser(str2);
        for (int i = strlen(str2); i < strlen(str1); i++){
            strcat(str2, "0");
        }
        inverser(str2);
    }
    if (len1 < len2) {
        inverser(str1);
        for (int i = len1; i < len2; i++){
            strcat(str1, "0");
        }
        inverser(str1);
    }

    // Opération
    int retenu = 0, result;
    for (int i = strlen(str1) - 1; i >= 0; i--){
        if (str1[i] - '0' >= str2[i] - '0' + retenu){
            result = (str1[i] - '0') - (str2[i] - '0' + retenu);
            retenu = 0;
            sum[i] = (result + '0');
        }
        else {
            result = (str1[i] - '0' + 10) - (str2[i] - '0' + retenu);
            retenu = 1;
            sum[i] = (result + '0');
        }
    }

    // Traitement des "0" en trop
    inverser(sum);
    int i = strlen(sum) - 1;
    while (sum[i] == '0' && i != 0){
        remove_char(sum, i);
        i--;
    }
    inverser(sum);

    // Si le resultat est négatif
    if (inverse){
        inverser(sum);
        strcat(sum, "-");
        inverser(sum);
    }

    printf("%s - %s = %s\n", a, b, sum);
    free(str1);
    free(str2);
    return sum;
}


char * multiplication(char *a, char *b){
    // Allocation mémoire
    char *res = malloc((strlen(a) + strlen(b) + 1 * sizeof(char)));
    char *str1 = malloc(50 * sizeof(char));
    char *str2 = malloc(50 * sizeof(char));

    strcpy(str1, a);
    strcpy(str2, b);

    // Operation
    int mul, i, j;
    memset(res, '0', strlen(str1) + strlen(str2));
    res[strlen(str1) + strlen(str2)] = 0;
    for (i = strlen(str1) - 1; i >= 0; i--){
        for (j = strlen(str2) - 1; j >= 0; j--){
            mul = (str1[i] - '0') * (str2[j] - '0');
            res[i + j] += ((res[i + j + 1] + mul - '0') / 10);
            res[i + j + 1] = ((res[i + j + 1] + mul - '0') % 10) + '0';
        }
    }

    // Traitement des "0" en trop
    inverser(res);
    i = strlen(res) - 1;
    while (res[i] == '0' && i != 0){
        remove_char(res, i);
        i--;
    }
    inverser(res);

    printf("%s * %s = %s\n",a , b, res);
    free(str1);
    free(str2);
    return res;
}

char * division(char *dividend,long divisor){
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
    char num2[50];
    if (argc != 2 || strcmp(argv[1], "usage") == 0){
        usage();
        return 0;
    }
    else if (strcmp(argv[1], "add") == 0){
        printf("Veuillez saisir le premier nombre : ");
        scanf("%s", num1);
        printf("Veuillez saisir le deuxième nombre : ");
        scanf("%s", num2);
        printf("\n");
        char *res = addition(num1, num2);
        free(res);
        return 1;
    }
    else if (strcmp(argv[1], "sub") == 0){
        printf("Veuillez saisir le premier nombre : ");
        scanf("%s", num1);
        printf("Veuillez saisir le deuxième nombre : ");
        scanf("%s", num2);
        printf("\n");
        char *res = substraction(num1, num2);
        free(res);
        return 1;
    }
    else if (strcmp(argv[1], "mul") == 0){
        printf("Veuillez saisir le premier nombre : ");
        scanf("%s", num1);
        printf("Veuillez saisir le deuxième nombre : ");
        scanf("%s", num2);
        printf("\n");
        char *res = multiplication(num1, num2);
        free(res);
        return 1;
    }
    else if (strcmp(argv[1], "div") == 0){
        long int num;
        printf("Veuillez saisir le premier nombre : ");
        scanf("%s", num1);
        printf("Veuillez saisir le deuxième nombre : ");
        scanf("%ld", &num);
        printf("\n");
        division(num1, num);
        return 1;
    }
    usage();
    return 0;
}