//
//  5_7_readlines.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/30.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "exercises.h"
#define MAXLEN 1000
#define MAXSTOR 100000

// 读取多行
int readlines_5_7(char *lineptr[], char *linestor, int maxlines) {
    int getline_5_6(char *, int);
    
    int nlines, len;
    char line[MAXLEN];
    
    char *start = linestor;
    char *end = linestor + MAXSTOR;
    
    nlines = 0;
    while ((len = getline_5_6(line, MAXLEN)) > 0) {
        if (nlines > maxlines || start + len > end) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(start, line);
            lineptr[nlines++] = start;
            start += len;
        }
    }
    return nlines;
}
