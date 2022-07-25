/**
 * @file private.h
 * @author Enzo Cornaggia (enzo.cornaggia@icloud.com)
 * @brief Structure for operation
 * @version 0.1
 * @date 2022-07-01
 *
 * @copyright Copyright (c) 2022
 *
 **/

#ifndef __PRIVATE_H__
#define __PRIVATE_H__

#include <string.h>

struct op_s {
    char* num1;
    char* num2;
    char* result;
    char* sresult;
};

typedef struct op_s op_s;

#endif


