//
//  4_7_calculator.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/3.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "calculator.h"

/**
 *  will push a entire string into the input
 */
void ungets(char s[]) {
    long len = strlen(s);
    void ungetch_(int);
    
    while (--len >= 0) {
        ungetch_(s[len]);
    }
}
