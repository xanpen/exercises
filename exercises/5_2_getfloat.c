//
//  5_2_getfloat.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/14.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include "calculator.h"

//get next floating-point nubmer from the input onto *pf
int getfloat_5_2(double *pf) {
    int c, sign;
    double power;
    
    // skip white space
    while (isspace(c = getch())) {
        ;
    }
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch_(c);
        return 0;
    }
    
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    
    //
    if (isdigit(c)) {
        for (*pf = 0.0; isdigit(c); c = getch()) {
            *pf = 10.0 * *pf + (c - '0');
        }
    }
    if (c == '.') {
        c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch()) {
        *pf = 10.0 * *pf + (c - '0');
        power *= 10;
    }
    
    
    *pf = sign * *pf / power;
    
    if (c != EOF) {
        ungetch_(c);
    }
    return c;
}
