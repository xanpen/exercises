//
//  7_7_pattern_finding.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/24.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

void findpattern(FILE *, char *, char *, int, int);

int main_7_7 (int argc, char *argv[]) {
    int c;
    int except = 0, number = 0;
    char pattern[MAXLINE];
    FILE *fp;
    
    // 解析命令行参数[-nx pattern file1 file2 ...]中的 -nx 部分
    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0])) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    fprintf(stderr, "find: illegal option %c\n", c);
                    argc = 0;
                    break;
            }
        }
    }
    // pattern 部分
    if (argc >= 1) {
        strcpy(pattern, argv[0]); // 或者 *argv
    } else {
        fprintf(stderr, "usage: find [-x] [-n] pattern [file1 file2 ...]\n");
        exit(1);
    }
    // file ... 部分
    if (argc == 1) {
        findpattern(stdin, "", pattern, except, number);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "find: can not open %s\n", argv[0]);
                exit(1);
            } else {
                findpattern(fp, argv[0], pattern, except, number);
                fclose(fp);
            }
        }
    }
    
    return 0;
}

// 从输入缓冲区循环读取一行，查找pattern
void findpattern(FILE *fp, char *fname, char *pattern, int except, int number) {
    char line[MAXLINE];
    long lineno = 0;
    
    while (fgets(line, MAXLINE, fp) != NULL) {
        ++lineno;
        if (((strstr(line, pattern)) != NULL) != except) {
            if (*fname) {
                printf("%s -", fname);
            }
            if (number) {
                printf("%ld ", lineno);
            }
            printf("%s ", line);
        }
    }
}

