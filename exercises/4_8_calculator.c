//
//  4_8_calculator.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/3.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#define BUFSIZE 100

static char bufc = 0;

/**
 *  get a (possibly pushed back) character
 */
int getch_4_8(void) {
    int c;
    
    if (bufc != 0) {
        c = bufc;
    } else {
        c = getchar();
    }
    bufc = 0;
    return c;
}

/**
 * push character back onto input
 */
void ungetch_4_8(int c) {
    if (bufc != 0) {
        printf("error: too many characters\n");
    } else {
        bufc = c;
    }
}
