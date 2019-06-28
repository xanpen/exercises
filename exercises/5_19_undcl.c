//
//  5_19_undcl.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/8.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "exercises.h"
#include "calculator.h"

#define MAXTOKEN    100
#define MAXOUT      1000

// name () [##]
enum {DCL_NAME, DCL_PERENS, DCL_BRACKETS};
enum {DCL_NO, DCL_YES};

extern char out[];
extern char token[];

// x () * [] * () char
// char (*((*x())[]))()
int main_5_19(int argc, char *argv[]) {
    int type;
    char temp[MAXTOKEN];
    
    while ((type = gettoken()) != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n') {
            if (type == DCL_PERENS || type == DCL_BRACKETS) {
                strcat(out, token);
            } else if (type == '*') {
                if ((type = nexttoken()) == DCL_PERENS || type == DCL_BRACKETS) {
                    sprintf(temp, "(*%s)", out);
                } else {
                    sprintf(temp, "*%s", out);
                }
                strcpy(out, temp);
            } else if (type == DCL_NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else {
                printf("invalid input at %s \n", token);
            }
        }
        printf("%s\n", out);
    }
    return 0;
}

// get the next token and put it back
int nexttoken(void) {
    int type;
    extern int prevtoken;
    type = gettoken();
    prevtoken = DCL_YES;
    return type;
}
