//
//  3_6_itoa_width.c
//  c_exercises
//
//  Created by wongxp on 2019/1/29.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

/// -123
void itoa_width(int n, char s[], int width) {
    int abs(int n);
    void reverse(char s[]);
    int sign, i;
    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    /// set blanks
    for (; i < width; i++) {
        s[i] = ' ';
    }
    
//    或者使用while
//    while (i < width) {
//        s[i++] = ' ';
//    }
    
    s[i] = '\0';
    reverse(s);
}
