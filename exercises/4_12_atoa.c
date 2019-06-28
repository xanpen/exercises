//
//  4_12_atoa.c
//  c_exercises
//
//  Created by wongxp on 2019/3/5.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <math.h>

/**
 *  recursive version
 */
void atoa_recursive(int n, char s[]) {
    static int i;
    
    if (n / 10) {
        atoa_recursive(n / 10, s);
    } else {
        i = 0;
        if (n < 0) {
            s[i++] = '-';
        }
    }
    s[i++] = abs(n) % 10 + '0';
    s[i] = '\0';
}
