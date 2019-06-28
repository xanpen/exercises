//
//  4_7_calculator.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/3.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#define BUFSIZE 100

static int buf[BUFSIZE];
static int bp = 0;

/**
 *  get a (possibly pushed back) character
 */
int getch_4_9(void) {
    return (bp > 0) ? buf[--bp] : getchar();
}

/**
 * push character back onto input
 */
void ungetch_4_9(int c) {
    if (bp >= BUFSIZE) {
        printf("error: too many characters\n");
    } else {
        buf[bp++] = c;
    }
}
