//
//  5_18_dcl.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/7.
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

int tokentype;              // type of last token
char token[MAXTOKEN];       // last token string
char name[MAXTOKEN];        // identifier name
char datatype[MAXTOKEN];    // data type = char, int, etc.
char out[MAXOUT];           // output string

int prevtoken = DCL_NO;

// convert declaration to words
int main_5_18 (int argc, char *argv[]) {
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n') {
            printf("syntax error\n");
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

// return next token
// char ( * ( * name () ) [] ) ()
int gettoken(void) {
    int c;
    int getch(void);
    void ungetch_(int c);
    char *p = token;
    
    // (*ABC_[]
    // 如果处理 (dcl)[] 时用户输入缺少了‘)’，即：（dcl[],这是要返回上一个token，即：'[',而不是']'
    // 这样能打印错误信息并保证程序继续按照用户输入期望的执行。
    if (prevtoken == DCL_YES) {
        prevtoken = DCL_NO;
        return tokentype;
    }

    while ((c = getch()) == ' ' || c == '\t') {
        ;
    }
    
    if (c == '(') { // () (##)
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = DCL_PERENS;
        } else {
            ungetch_(c);
            return tokentype = '(';
        }
    } else if (c == '[') { // [##]
        for (*p++ = c; (*p++ = c = getch()) != ']';) {
            ;
        }
        *p = '\0';
        return tokentype = DCL_BRACKETS;
    } else if (isalpha(c)) { // name
        for (*p++ = c; isalnum(c = getch());) {
            *p++ = c;
        }
        *p = '\0';
        ungetch_(c);
        return tokentype = DCL_NAME;
    } else { // *
        return tokentype = c;
    }
}
// dcl: parse a declaration
void dcl(void) {
    int ns;
    for (ns = 0; gettoken() == '*';) {
        ns++;
    }
    dirdcl();
    while (ns-- > 0) {
        strcat(out, " pointer to");
    }
}
// dirdcl: parse a direct declaration
void dirdcl(void) {
    int type;
    
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            errormsg("error: missing )\n");
        }
    } else if (tokentype == DCL_NAME) {
        strcpy(name, token);
    } else {
        errormsg("error: no name or (dcl) \n");
    }
    
    while ((type = gettoken()) == DCL_PERENS || type == DCL_BRACKETS) {
        if (type == DCL_PERENS) {
            strcat(out, " function returning");
        } else {
            strcat(out, " arrays");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}
// error
void errormsg(char *msg) {
    printf("%s\n", msg);
    prevtoken = DCL_YES;
}
