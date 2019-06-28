//
//  index.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/2.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

#define MAXOP 100

/**
 *  reverse polish calculator
 *
 */
void calc(void) {
    int type;
    char s[MAXOP];
    double op2;
    
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
                    printf("error: zero devision\n");
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
