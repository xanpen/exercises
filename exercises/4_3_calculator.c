//
//  4_3_calculator.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/2.
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
 *  an improved version of reverse polish calculator 4-3
 *
 */
void calc_4_3(void) {
    int type;
    char s[MAXOP];
    double op2;
    
    while ((type = getop_4_3(s)) != EOF) {
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
            case '%':
                op2 = pop();
                if (op2 == 0.0) {
                    printf("error: zero devisor\n");
                } else {
                    push(fmod(pop(), op2));
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}

/**
 *  getop_4_3: 支持负号
 */
int getop_4_3(char s[]) {
    int i, c;
    // 过滤空格和tab
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    // 收集操作符：如果是非数字非小数点，保证字符串s完整
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;
    }
    i = 0;
    // 收集负号,减号（区分负号和减号，负号后面跟数字或者小数点）
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;
        } else {
            if (c != EOF) {
                ungetch_(c);
            } else {
                return '-';
            }
        }
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

