//
//  5_17_sort.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/5.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "exercises.h"

#define LINES       100
#define NUMERIC     1
#define DECR        2
#define FOLD        4
#define DIR         8
#define MAXSTR      100

char option = 0;
int pos1 = 0;
int pos2 = 0;

int main_5_17(int argc, char *argv[]) {
    char *lineptr[LINES];
    int nlines;
    int result = 0;
    readargs(argc, argv);
    if ((nlines = readlines_5_14(lineptr, LINES)) > 0) {
        if (option & NUMERIC) {
            qsort_5_14((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp_5_17);
        } else {
            qsort_5_14((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))charcmp_5_17);
        }
        writelines_5_14(lineptr, nlines, option & DECR);
    } else {
        printf("input too big to sort \n");
        result = -1;
    }
    return result;
}

// 读取程序命令行参数
void readargs(int argc, char *argv[]) {
    extern char option;
    extern int pos1;
    extern int pos2;
    int c = 0;
    
    while ((--argc > 0 && (c = (*++argv)[0]) == '-') || c == '+') {
        if (c == '-' && !isdigit(*(argv[0] + 1))) {
            while ((c = *++argv[0])) {
                switch (c) {
                    case 'n':
                        option |= NUMERIC;
                        break;
                    case 'f':
                        option |= FOLD;
                        break;
                    case 'd':
                        option |= DIR;
                        break;
                    case 'r':
                        option |= DECR;
                        break;
                        
                    default:
                        printf("sort : illegal option %c \n", c);
                        error("usage1: sort -nfdr [+pos1] [-pos2] \n");
                        break;
                }
            }
        } else if (c == '-') {
            pos2 = atoi(argv[0] + 1);
        } else if ((pos1 = atoi(argv[0] + 1)) < 0) {
            error("usage2: sort -nfdr [+pos1] [-pos2] \n");
        }
    }
    
    if (argc || pos1 > pos2) {
        error("usage3: sort -nfdr [+pos1] [-pos2] \n");
    }
}

int numcmp_5_17(char *s1, char *s2) {
    double v1, v2;
    char str[MAXSTR];
    
    substr_5_17(s1, str, MAXSTR);
    v1 = atof(str);
    substr_5_17(s2, str, MAXSTR);
    v2 = atof(str);

    if (v1 < v2) {
        return -1;
    } else if (v1 > v2) {
        return 1;
    } else {
        return 0;
    }
}

int charcmp_5_17(char *s1, char *s2) {
    extern char option;
    extern int pos1, pos2;
    char a = 0, b = 0;
    
    int fold = (option & FOLD) ? 1 : 0;
    int dir = (option & DIR) ? 1 : 0;
    
    int i, j, endpos;
    i = j = pos1;
    if (pos2 > 0) {
        endpos = pos2;
    } else if ((endpos = (int)strlen(s1)) > (int)strlen(s2)) {
        endpos = (int)strlen(s2);
    }
    
    do {
        if (dir) {
            while (i < endpos && !isalnum(s1[i]) && s1[i] != ' ' && s1[i] != '\0') {
                i++;
            }
            while (j < endpos && !isalnum(s2[j]) && s2[j] != ' ' && s2[j] != '\0') {
                j++;
            }
        }
        if (i < endpos && j < endpos) {
            a = fold ? tolower(s1[i]) : s1[i];
            i++;
            b = fold ? tolower(s2[j]) : s2[j];
            j++;
            if (a == b && a == '\0') {
                return 0;
            }
        }
    } while (a == b && i < endpos && j < endpos);
    return  a - b;
}

void substr_5_17(char *s, char *str, int maxstr) {
    extern int pos1, pos2;
    extern char option;
    int i, j, len;
    
    len = (int)strlen(s);
    if (pos2 > 0 && pos2 < len) {
        len = pos2;
    } else if (pos2 > 0 && pos2 > len) {
        error("substr: too short\n");
    }
    
    for (j = 0, i = pos1; i < len && j < maxstr; i++, j++) {
        str[j] = s[i];
    }
    str[j] = '\0';
}
