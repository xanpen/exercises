//
//  5_13_tail.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/3.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercises.h"

#define MAXLEN      100
#define LINES       100
#define DFTLINES    10

void error(char *msg);

// 1,存储缓冲区的循环复用
// 2,指针数组的循环复用
// 3,打印最后n行：
//      情况1：last>=n, 从first=last-n到last
//      情况2：last<n, 从first=last-n+lines到last
//     （例如：数组大小0~99，first=50，那最后n=100行就是：50~99片段 和 0~49片段。用求模控制）
int main_5_13(int argc, char *argv[]) {

    char *p;
    char *buf;
    char *bufend;
    
    char *lineptr[LINES];
    int last;
    
    char line[MAXLEN];
    int n = 0, i, len, nlines;
    int first;
    
    //printf("%c\n", **++argv);
    //printf("%d\n", atoi(*argv+1));
    
    // 解析处理命令行参数
    if (argc == 1) {
        n = DFTLINES;
    } else if (argc == 2 && **++argv == '-') {
        n = atoi(&(*argv)[1]);
    } else {
        error("usage: tail [-n]");
    }
    if (n < 1 || n > LINES) {
        n = LINES;
    }
    // 分配缓冲区
    if ((p = buf = malloc(LINES * MAXLEN)) == NULL) {
        error("error: can not allocate buf");
    }
    bufend = buf + (LINES * MAXLEN);
    
    // 初始化指针数组
    for (i = 0; i < LINES; i++) {
        lineptr[i] = NULL;
    }
    
    // 读取多行
    last = 0;
    nlines = 0;
    while ((len = getline_5_6(line, MAXLEN)) > 1) {
        //printf("%d", len);
        //
        if (p + len + 1 >= bufend) {
            p = buf;
        }
        strcpy(p, line);
        //
        lineptr[last] = p;
        if (++last >= LINES) {
            last = 0;
        }
        p += len + 1;
        nlines++;
    }
    // 打印最后n行
    if (n > nlines) {
        n = nlines;
    }
    first = last - n;
    if (first < 0) {
        first += LINES;
    }
    for (i = first; n-- > 0; i = (i + 1) % LINES) {
        printf("%s", lineptr[i]);
    }
    return 0;
}

// 错误信息
void error(char *msg) {
    printf("error: %s\n", msg);
    exit(1);
}
