//
//  4_5_calculator.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/3.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "calculator.h"

#define MAXOP 100
/**
 *  an improved version of reverse polish calculator 4-5
 *
 */
void calc_4_5(void) {
    int type;
    char s[MAXOP];
    double op2;
    
    while ((type = getop_4_5(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                op2 = pop();
                if (op2 == 0.0) {
                    printf("error: zero devisor\n");
                } else {
                    push(pop() / op2);
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case NAME:
                mathfnc(s);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}

/**
 *  getop_4_5: 支持函数名
 */
int getop_4_5(char s[]) {
    int i, c;
    // 过滤空格和tab
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    i = 0;
    
    // 收集函数名
    if (islower(c)) {
        while (islower((s[++i] = c = getch()))) {
            ;
        }
        s[i] = '\0';
        if (c != EOF) {
            ungetch_(c);
        }
        
        if (strlen(s) > 1) {
            return NAME;
        } else {
            return c;
        }
    }
    
    // 收集操作符：如果是非数字非小数点，保证字符串s完整
    if (!isdigit(c) && c != '.') {
        return c;
    }
    
    // 收集操作数
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    // 收集操作数（小数点部分）
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    // 因为s[i]此时储存的是非数字非小数点，所以直接以为\0覆盖掉
    s[i] = '\0';
    // 是否需要压回input输入缓冲区
    if (c != EOF) {
        ungetch_(c);
    }
    
    return NUMBER;
}

/**
 *  check string s for supported math functions
 */
void mathfnc(char s[]) {
    double op2;
    
    if (strcmp(s, "sin") == 0) {
        push(sin(pop()));
    } else if (strcmp(s, "cos") == 0) {
        push(cos(pop()));
    } else if (strcmp(s, "exp") == 0) {
        push(exp(pop()));
    } else if (strcmp(s, "pow") == 0) {
        printf("test");
        op2 = pop();
        push(pow(pop(), op2));
    } else {
        printf("error: %s not supported \n", s);
    }
}
