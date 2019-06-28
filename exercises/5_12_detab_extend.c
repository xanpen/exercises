//
//  5_12_detab_extend.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/3.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100
#define YES     1
#define NO      0
#define TABINC  8

// 设置“标尺”；根据命令行参数-m +n参数设置在数组tab中的起始的tab结束位和其间隔
void esettab(int argc, char *argv[], char *tab) {
    int pos, inc;
    int i;
    
    // 默认方式: 无命令行参数; 命令行模式:-m +n; 命令行模式:参数列表;
    if (argc <= 1) {
        for (i = 1; i <= MAXLINE; i++) {
            if (i % TABINC == 0) {
                tab[i] = YES;
            } else {
                tab[i] = NO;
            }
        }
    } else if (argc == 3 && *argv[1] == '-' && *argv[2] == '+') {
        pos = atoi(&(*++argv)[1]);
        inc = atoi(&(*++argv)[1]);
        for (i = 1; i <= MAXLINE; i++) {
            if (i != pos) {
                tab[i] = NO;
            } else {
                tab[i] = YES;
                pos += inc;
            }
        }
    } else {
        for (i = 1; i <= MAXLINE; i++) {
            tab[i] = NO;
        }
        while (--argc > 0) {
            pos = atoi(*++argv);
            if (pos > 0 && pos <= MAXLINE) {
                tab[pos] = YES;
            }
        }
    }
}
