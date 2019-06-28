//
//  5_20_dcl_expand.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/9.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "exercises.h"

#define MAXTOKEN    100
#define MAXOUT      1000

enum {DCL_NAME, DCL_PERENS, DCL_BRACKETS};
enum {DCL_NO, DCL_YES};

extern int tokentype;
extern char token[];
extern char name[];
extern char datatype[];
extern char out[];
extern int prevtoken;


void dcl_5_20(void);
void dirdcl_5_20(void);

void dclspec(void);
int typespec(void);
int typequal(void);
int compare(char **, char **);

int main_5_20 (int argc, char *argv[]) {
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl_5_20();
        if (tokentype != '\n') {
            printf("syntax error!\n");
        }
        printf("%s %s %s", name, out, datatype);
    }
    return 0;
}

// dcl
void dcl_5_20(void) {
    int ns;
    for (ns = 0; gettoken() == '*';) {
        ns++;
    }
    dirdcl_5_20();
    while (ns-- > 0) {
        strcat(out, " pointer to");
    }
}

// dirdcl
void dirdcl_5_20(void) {
    int type;
    void parmdcl(void);
    
    if (tokentype == '(') {
        dcl_5_20();
        if (tokentype != ')') {
            errormsg("error: missing )\n");
        }
    } else if (tokentype == DCL_NAME) {
        if (name[0] == '\0') {
            strcpy(name, token);
        }
    } else {
        prevtoken = DCL_YES;
    }
    
    while ((type = gettoken()) == DCL_PERENS || type == DCL_BRACKETS || type == '(') {
        if (type == DCL_PERENS) {
            strcat(out, " function returning");
        } else if (type == '(') {
            strcat(out, " function excepting");
            parmdcl();
            strcat(out, " and returning");
        } else if (type == DCL_BRACKETS) {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

// 参数列表，例如：const char *, int *, int (*fnc)(), ...
void parmdcl(void) {

    do {
        dclspec();
    } while (tokentype == ',');
    if (tokentype != ')') {
        errormsg("error: missing ) in parameter declaration\n");
    }
}

// 参数，例如：const char *
void dclspec(void) {
    char temp[MAXTOKEN];
    temp[0] = '\0';
    
    gettoken();
    do {
        if (tokentype != DCL_NAME) {
            prevtoken = DCL_YES;
            dcl_5_20();
        } else if (typespec() == DCL_YES) {
            strcat(temp, " ");
            strcat(temp, token);
            gettoken();
        } else if (typequal() == DCL_YES) {
            strcat(temp, " ");
            strcat(temp, token);
            gettoken();
        } else {
            errormsg("unknown type in parameter list\n");
        }
    } while (tokentype != ',' && tokentype != ')');
    
    strcat(out, temp);
    if (tokentype == ',') {
        strcat(out, ",");
    }
}

// token是否是类型说明符
int typespec(void) {
    static char *types[] = {
        "char",
        "int",
        "void"
    };
    
    char *pt = token;
    if (bsearch(&pt, types, sizeof(types)/sizeof(char *), sizeof(char *), compare) == NULL) {
        return DCL_NO;
    } else {
        return DCL_YES;
    }
}

// token是否是类型修饰符
int typequal(void) {
    static char *typeq[] = {
        "const",
        "volatile",
    };
    char *pt = token;
    
    if (bsearch(&pt, typeq, sizeof(typeq)/sizeof(char *), sizeof(char *), compare) == NULL) {
        return DCL_NO;
    } else {
        return DCL_YES;
    }
}

// 二级指针比较函数
int compare(char **s, char **t) {
    return strcmp(*s, *t);
}
