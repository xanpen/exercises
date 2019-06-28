//
//  5_6_pointer_version.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/28.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calculator.h"

// 利用指针方式改写之前章节的某些函数
// getline atoi reverse strindex getop

// 读取一行到字符数组中
int getline_5_6(char *s, int lim) {
    int i = 0, c = 0;
    char *s_start = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        i++;
    }
    if (c == '\n') {
        *s++ = c;
        i++;
    }
    *s = '\0';
    return (int)(s - s_start);
}

// 转换字符串s为integer的指针版本
int atoi_5_6(char *s) {
    int n, sign;
    
    while (isspace(*s)) {
        s++;
    }
    
    if (*s == '-')
        sign = -1;
    else
        sign = 1;
    if (*s == '-' || *s == '+') {
        s++;
    }
    
    for (n = 0; isdigit(*s); s++) {
        n = 10 * n + (*s - '0');
    }
    return sign * n;
}

// integer转字符串
void itoa_5_6(int n, char *s) {
    int sign;
    char *t = s;
    void reverse_5_6(char *);
    
    if ((sign = n) < 0) {
        n = -n;
    }
    
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        *s++ = '-';
    }
    *s = '\0';
    reverse_5_6(t);
}

// 字符串翻转
void reverse_5_6(char *s) {
    char *t;
    char tmp;
    for (t = s + strlen(s); s < t; s++, t--) {
        tmp = *s;
        *s = *t;
        *t = tmp;
    }
}

// 查找t在s中首次出现的位置，未找到返回-1
int strindex_5_6(char *s, char *t) {
    char *b = s;
    char *p, *r;
    
    for (; *s != '\0'; s++) {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++) {
            ;
        }
        if (r > t && *r == '\0') {
            return (int)(s - b);
        }
    }
    return -1;
}

// 转换字符串s为浮点数（指针版本）
double atof_5_6(char *s) {
    int sign;
    double n, power;
    
    while (isspace(*s)) {
        s++;
    }
    sign = (*s == '-') ? -1 : 1;
    if (*s == '-' || *s == '+') {
        s++;
    }
    for (n = 0.0; isdigit(*s); s++) {
        n = 10.0 * n + (*s - '0');
    }
    if (*s == '.') {
        s++;
    }
    for (power = 0.0; isdigit(*s); s++) {
        n = 10.0 * n + (*s - '0');
        power *= 10.0;
    }
    return sign * n / power;
}

// 获取下一个操作符或者操作数（指针版本）
int getop_5_6(char *s) {
    int getch(void);
    void ungetch_(int);
    int c;
    
    while ((*s = c = getch()) == ' ' || c == '\t') {
        ;
    }
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.') {
        return c;
    }
    if (isdigit(c)) {
        while (isdigit(*++s = c = getch())) {
            ;
        }
    }
    if (c == '.') {
        while (isdigit(*++s = c = getch())) {
            ;
        }
    }
    *s = '\0';
    if (c != EOF) {
        ungetch_(c);
    }
    return NUMBER;
}
