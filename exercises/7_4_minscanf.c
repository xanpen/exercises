//
//  7_4_minscanf.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/21.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

#define LOCALFMT    100

void minscanf(char *fmt, ...);

int main_7_4 (int argc, char *argv[]) {
    float i;

    minscanf("num:%f", &i);
    //scanf("num:%lf", &i);
    printf("(num:%f)", i);
    
    return 0;
}

// minscanf("aa%2d/%2d/%2d", ...)
void minscanf(char *fmt, ...) {
    va_list ap; // 指针：轮流指向每一个未命名参数
    char localfmt[LOCALFMT];
    char *sval;
    int *ival;
    unsigned *uval;
    float *dval;
    
    char *p;
    int i;
    
    va_start(ap, fmt);
    i = 0;
    for (p = fmt; *p; p++) {

        if (*p != '%') {
            localfmt[i++] = *p;
            continue;
        }
        localfmt[i++] = '%';
        while (*(p+1) && !isalpha(*(p+1))) {
            localfmt[i++] = *++p;
        }
    
        
        localfmt[i++] = *(p+1);
        localfmt[i] = '\0';
        
        switch (*++p) {
            case 'd':
            case 'i':
                ival = va_arg(ap, int *);
                scanf(localfmt, ival);
                break;
            case 'x':
            case 'X':
            case 'o':
            case 'u':
                uval = va_arg(ap, unsigned *);
                scanf(localfmt, uval);
                break;
            case 'f':
                //printf("%s\n", localfmt);
                dval = va_arg(ap, float *);
                scanf(localfmt, dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf(localfmt, sval);
                break;
            default:
                scanf(localfmt);
                break;
        }
        i = 0;
    }
    va_end(ap);
}







