//
//  5_5_strncpy.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/28.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>

// t="123456"
// s="abcdef"
void strncpy_5_5(char *s, char *t, int n) {
    while (n-- > 0 && (*s++ = *t++) != '\0')
        ;
}
// 如果n大于t的长度，剩余的用'\0'填充
void strncpy_5_5_2(char *s, char *t, int n) {
    while (*t && n-- > 0) {
        *s++ = *t++;
    }
    while (n-- > 0) {
        *s++ = '\0';
    }
}
// t="123"
// s="abc"
void strncat_5_5(char *s, char *t, int n) {
    while (*s) {
        s++;
    }
    while (n-- > 0 && (*s++ = *t++) != '\0')
        ;
}
// 使用strncpy,strlen等实现
void strncat_5_5_2(char *s, char *t, int n) {
    void strncpy_5_5_2(char *, char *, int);
    
    strncpy_5_5_2((s + strlen(s)), t, n);
}
// t = "1234sss"
// s = "123abc"
int strncmp_5_5(char *s, char *t, int n) {
    for (; *t == *s; s++,t++) {
        if (*s == '\0' || --n <= 0) {
            return 0;
        }
    }
    return *s - *t;
}
