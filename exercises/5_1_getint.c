//
//  5_1_getint.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/14.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include "calculator.h"

// get next integer from the input onto *pn
int getint_5_1(int *pn) {
    int c, c_, sign;
    
    // skip white space
    while (isspace(c = getch())) {
        ;
    }
    // return 0 if it is not a number
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch_(c);
        return 0;
    }
    // sign
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c_ = c;
        if (!isdigit(c = getch())) {
            if (c != EOF) {
                ungetch_(c);
            }
            ungetch_(c_);
            return c_;
        }
    }
    // return positive if it is a number
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    
    if (c != EOF) {
        ungetch_(c);
    }
    
    return c;
}
