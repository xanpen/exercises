//
//  4_6_calculator.c
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
 *  an improved version of reverse polish calculator 4-3
 *
 */
void calc_4_6(void) {
    int type, var = 0, i = 0;
    char s[MAXOP];
    double op2, v = 0.0;
    double variable[26];
    
    // 初始化变量
    while (i < 26) {
        variable[i++] = 0.0;
    }
    
    while ((type = getop(s)) != EOF) {
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
                v = pop();
                printf("\t%.8g\n", v);
                break;
            case '=':
                pop();
                variable[var - 'A'] = pop();
                break;
            default:
                if (type >= 'A' && type <= 'Z') {
                    push(variable[type - 'A']);
                } else if (type == 'v') {
                    push(v);
                } else {
                    printf("error: unknown command %s\n", s);
                }
                break;
        }
        var = type;
    }
}
