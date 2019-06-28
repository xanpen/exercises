//
//  3_5_itob.c
//  c_exercises
//
//  Created by wongxp on 2019/1/29.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
/// itob(255, s, 16)
void itob(int n, char s[], int b) {
    void reverse(char s[]);
    int i, sign;
    int j;
    if ((sign = n) < 0) {
        n = - n;
    }
    
    i = 0;
    do {
        j = n % b;
        s[i++] = (j <= 9) ? j + '0' : j - 10 + 'a';
    } while ((n /= b) != 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
