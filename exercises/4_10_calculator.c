//
//  4_10_calculator.c
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
#define MAXLINE_ 1000

static char line[MAXLINE_];
static int li = 0;

/**
 *  an improved version of reverse polish calculator 4-10
 *
 */
void calc_4_10(void) {
    int type;
    char s[MAXOP];
    double op2;
    
    while ((type = getop_4_10(s)) != EOF) {
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
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}

/**
 *  getop_4_10: getline
 */
int getop_4_10(char s[]) {
    int i, c;
    
    // 如果尚未读入一行（空字符串的s[0]为:\0）
    // 或者确实已经读入了一行，但是已经取到了该行的末尾，也就是:\0
    if (line[li] == '\0') {
        if ((getline_v2(line, MAXLINE_)) == 0) {
            return EOF;
        } else {
            li = 0;
        }
    }
    
    // 过滤空格和tab
    while ((s[0] = c = line[li++]) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    
    // 收集操作符：如果是非数字非小数点，保证字符串s完整
    if (!isdigit(c) && c != '.') {
        return c;
    }
    i = 0;
    // 收集操作数
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = line[li++])) {
            ;
        }
    }
    // 收集操作数（小数点部分）
    if (c == '.') {
        while (isdigit(s[++i] = c = line[li++])) {
            ;
        }
    }
    // 因为s[i]此时储存的是非数字非小数点，所以直接以为\0覆盖掉
    s[i] = '\0';
    // 是否需要压回input输入缓冲区
    li--;
    
    return NUMBER;
}
