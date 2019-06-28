//
//  4_4_calculator.c
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
 *  an improved version of reverse polish calculator 4-4
 *
 */
void calc_4_4(void) {
    int type;
    char s[MAXOP];
    double op1, op2;
    
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
                printf("\t%.8g\n", pop());
                break;
            case 'c': /* clear the stack */
                clear_();
                break;
            case 's': /* swap the top two elements of the stack */
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'd': /* duplicate the top element of the stack */
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case '?': /* print the top element of the stack without popping */
                op2 = pop();
                printf("?\t%.8g\n", op2);
                push(op2);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
}
