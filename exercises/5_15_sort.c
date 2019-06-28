//
//  5_15_sort.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/4.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "exercises.h"

#define LINES   100
#define NUMERIC 1
#define DECR    2
#define FOLD    4

static char option = 0;

int main_5_15(int argc, char *argv[])
{
    int nlines;
    int result = 0;
    char *lineptr[LINES];
    int c;
    
    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++*argv)) {
            switch (c) {
                case 'n':
                    option |= NUMERIC;
                    break;
                case 'r':
                    option |= DECR;
                    break;
                case 'f':
                    option |= FOLD;
                    break;
                    
                default:
                    printf("sort: illegal option %c \n", c);
                    argc = 1;
                    result = -1;
                    break;
            }
        }
    }
    
    if (argc) {
        printf("usage: sort [-fnr]");
    } else {
        if ((nlines = readlines_5_14(lineptr, LINES)) > 0) {
            if (option & NUMERIC) {
                qsort_5_14((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp_5_14);
            } else if (option & FOLD) {
                qsort_5_14((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))charcmp_5_15);
            } else {
                qsort_5_14((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))strcmp_5_14);
            }
            writelines_5_14(lineptr, nlines, option & DECR);
        } else {
            printf("input too big to sort \n");
            result = -1;
        }
    }
    return result;
}

// 忽略大小写
int charcmp_5_15(char *s1, char *s2) {
    
    for (; tolower(*s1) == tolower(*s2); s1++, s2++) {
        if (*s1 == '\0') {
            return 0;
        }
    }
    return tolower(*s1) - tolower(*s2);
}


