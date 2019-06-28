//
//  7_3_minprintf.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/21.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define LOCALFMT   100

void minprintf(char *, ...);

int main_7_3 (int argc, char *argv[]) {
    printf("int: %d\nx:%0x\no:%o\nf:%f\ns:%s\n", 16, 16, 16, 16.1616, "1166");
    minprintf("int: %d\nx:%0x\no:%o\nf:%f\ns:%s\n", 16, 16, 16, 16.1616, "1166");
    return 0;
}

// int: %d\nx:%0x\no:%o\nf:%f\ns:%s\n
void minprintf(char *fmt, ...) {
    va_list ap; // 指针：轮流指向每一个未命名参数
    char *sval;
    int ival;
    double dval;
    unsigned uval;
    char *p;
    int i;
    
    char localfmt[LOCALFMT];
    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        // 非 % 字符
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        
        // 收集localfmt %03d
        i = 0;
        localfmt[i++] = '%';
        while (*(p + 1) && !isalpha(*(p + 1))) {
            localfmt[i++] = *++p;
        }
        localfmt[i++] = *(p + 1);
        localfmt[i] = '\0';
        
        // format letter
        switch (*++p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int);
                printf(localfmt, ival);
                break;
            case 'x':
            case 'X':
            case 'o':
            case 'u':
                uval = va_arg(ap, unsigned);
                printf(localfmt, uval);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf(localfmt, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf(localfmt, sval);
                break;
            default:
                printf("%s", localfmt);
                break;
        }
    }
    va_end(ap);
}
