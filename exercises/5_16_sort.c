//
//  5_16_sort.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/4.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "exercises.h"

#define LINES       100
#define NUMERIC     1
#define DECR        2
#define FOLD        4
#define DIR         8

static char option = 0;

int main_5_16(int argc, char *argv[])
{
    char *lineptr[LINES];
    int result = 0;
    int c;
    int nlines;
    
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
                case 'd':
                    option |= DIR;
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
        printf("usage: sort [-nrfd] \n");
    } else {
        if ((nlines = readlines_5_14(lineptr, LINES)) > 0) {
            if (option & NUMERIC) {
                qsort_5_14((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))numcmp_5_14);
            } else {
                qsort_5_14((void **)lineptr, 0, nlines-1, (int (*)(void *, void *))charcmp_5_16);
            }
            writelines_5_14(lineptr, nlines, option & DECR);
        } else {
            printf("input to big to sort \n");
            result = -1;
        }
    }
    
    return result;
}

int charcmp_5_16(char *s1, char *s2) {
    char a, b;
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & DIR) ? 1 : 0;
    do {
        if (dir) {
            while (!isalnum(*s1) && *s1 != ' ' && s1 != '\0') {
                s1++;
            }
            while (!isalnum(*s2) && *s2 != ' ' && s2 != '\0') {
                s2++;
            }
        }
        if (fold) {
            a = tolower(*s1);
            b = tolower(*s2);
        } else {
            a = *s1;
            b = *s2;
        }
        s1++;
        s2++;
        
        if (a == b && a == '\0') {
            return 0;
        }
    } while (a == b);
    return a - b;
}
