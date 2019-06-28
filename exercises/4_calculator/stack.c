//
//  stack.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/2.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#define MAXVAL 100

static double var[MAXVAL];
static int sp = 0;

/**
 *  push f onto value stack
 */
void push(double f) {
    if (sp >= MAXVAL) {
        printf("error: stack full, can't push %g\n", f);
    } else {
        var[sp++] = f;
    }
}

/**
 *  pop and return top value from stack
 */
double pop(void) {
    if (sp <= 0) {
        printf("error: stack empty\n");
        return 0.0;
    } else {
        return var[--sp];
    }
}

/**
 *  clear the stack (for 4_4)
 */
void clear_(void) {
    sp = 0;
}
