//
//  3_4_itoa.c
//  c_exercises
//
//  Created by wongxp on 2019/1/29.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

/// 假设32位字长机器，two's complement 有符号数表示范围-（2的31次方） ~ （2的31次方-1）
/// 当n=Tmin(32)时，n = -n，导致n大于Tmax(32)

void itoa_v2(int n, char s[]) {
    int sign, i;
    void reverse(char s[]);
    int abs(int n);
    
    sign = n;
    i = 0;
    do {
        s[i++] = abs((n % 10)) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int abs(int n) {
    return (n < 0) ? (-n) : n;
}

/// -123
void itoa(int n , char s[]) {
    int sign, i;
    void reverse(char s[]);
    if ((sign = n) < 0) {
        n = -n;
    }
    i = 0;
    do {
        s[i++] = (n % 10) + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

///
void reverse(char s[]) {
    int i, j;
    char temp;
    i = 0;
    while (s[i] != '\0') {
        i++;
    }
    i--;
    if (s[i] == '\n') {
        i--;
    }
    j = 0;
    while (j < i) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        j++;
        i--;
    }
}
