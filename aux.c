#include "aux.h"

#include <stdbool.h>
#include <string.h>

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