//
//  5_14_sort.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/4.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "exercises.h"

#define MAXLEN  1000
#define NUMERIC 1
#define DECR    2
#define LINES   100

static char option = 0;

int main_5_14 (int argc, char *argv[]) {
    char *lineptr[LINES];
    int nlines;
    int c;
    int result = 0;
    
    // 解析和处理命令行参数
    while (--argc > 0 && (*++argv)[0] == '-') {
        // *++*argv
        while ((c = *++argv[0])) {
            switch (c) {
                case 'n':
                    option |= NUMERIC;
                    break;
                case 'r':
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c\n", c);
                    argc = 1;
                    result = -1;
                    break;
            }
        }
    }
    // 有其他命令行参数，但不是以‘-’开头
    if (argc) {
        printf("usage: sort [-nr]\n");
    } else {
        if ((nlines = readlines_5_14(lineptr, LINES)) > 0) {
            if (option & NUMERIC) {
                qsort_5_14((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))numcmp_5_14);
            } else {
                qsort_5_14((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))strcmp_5_14);
            }
            writelines_5_14(lineptr, nlines, option & DECR);
        } else {
            printf("input too many to sort \n");
            result = -1;
        }
    }
    
    return result;
}

// 从输入缓冲区读取多行
int readlines_5_14(char *lineptr[], int maxlines) {
    int len;
    int nlines;
    char *p;
    char line[MAXLEN];
    
    nlines = 0;
    while ((len = getline_5_6(line, MAXLEN)) > 1) {
        if (nlines >= maxlines || (p = malloc(len)) == NULL) {
            return  -1;
        } else {
            // 覆盖\n
            // abc\n\0 len=4
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}
// 往输出缓冲区写入多行
void writelines_5_14(char *lineptr[], int nlines, int decr) {
    if (decr) {
        int i;
        for (i = nlines - 1; i >= 0; i--) {
            printf("%s\n", lineptr[i]);
        }
    } else {
        while (nlines-- > 0) {
            printf("%s\n", *lineptr++);
        }
    }
}

// 字符串的数字比较
int numcmp_5_14(char *s1, char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2) {
        return -1;
    } else if (v1 == v2) {
        return 0;
    } else {
        return 1;
    }
}

// 字符串的字典排序
int strcmp_5_14(char *s1, char *s2) {
    
    for (; *s1 == *s2; s1++, s2++) {
        if (s1 == '\0') {
            return 0;
        }
    }
    return *s1 - *s2;
}

// 指针数组的交换
void swap_5_14(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

// 快速排序：increasing order
void qsort_5_14(void *v[], int left, int right, int (*comp)(void *, void *)) {
    void swap_5_14(void *v[], int, int);
    int i, last;
    
    if (left >= right) {
        return;
    }
    swap_5_14(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++) {
        if ((*comp)(v[i], v[left]) < 0) {
            swap_5_14(v, ++last, i);
        }
    }
    swap_5_14(v, last, left);
    qsort_5_14(v, 0, last - 1, comp);
    qsort_5_14(v, last + 1, right, comp);
}
