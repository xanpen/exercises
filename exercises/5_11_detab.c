//
//  5_11_detab.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/2.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100
#define YES     1
#define NO      0
#define TABINC  8

void settab(int argc, char *argv[], char *tab);
void entab(char *tab);
void detab(char *tab);
int tabpos(int pos, char *tab);

#include "exercises.h"

int main_5_11(int argc, char *argv[]) {
    char tab[MAXLINE + 1];
    // 设置“标尺”
    settab(argc, argv, tab);
    entab(tab);
    return 0;
}

// 设置“标尺”；在数组tab中设置制表符结束位
void settab(int argc, char *argv[], char *tab) {
    int pos, i;
    // 默认方式
    if (argc <= 1) {
        for (i = 1; i <= MAXLINE; i++) {
            if (i % TABINC != 0) {
                tab[i] = NO;
            } else {
                tab[i] = YES;
            }
        }
    } else {
        for (i = 0; i <= MAXLINE; i++) {
            tab[i] = NO;
        }
        while (--argc > 0) {
            pos = atoi(*++argv);
            if (pos >= 1  && pos <= MAXLINE) {
                tab[pos] = YES;
            }
        }
    }
}

// 空格串-->制表符&空格
void entab(char *tab) {
    int c, pos;
    int nb = 0, nt = 0;
    
    for (pos = 1; (c = getchar()) != EOF; pos++) {
        // 可能出现：空格 \n \t 普通字符
        if (c == ' ') {
            if (tabpos(pos, tab) == NO) {
                ++nb;
            } else {
                nb = 0;
                ++nt;
            }
        } else {
            // 打印积攒的制表符
            for (; nt > 0; nt--) {
                putchar('#');
            }
            // 打印积攒的空格
            if (c == '\t') {
                nb = 0;
            } else {
                for (; nb > 0; nb--) {
                    putchar('*');
                }
            }
            // 打印普通字符
            if (c == '\t') {
                putchar('#');
            } else {
                putchar(c);
            }
            
            // \n 和 \t 的特殊处理pos位置
            if (c == '\n') {
                pos = 0;
            } else if (c == '\t') {
                while (tabpos(pos, tab) != YES) {
                    ++pos;
                }
            }
        }
    }
}

// 制表符-->空格
void detab(char *tab) {
    int c, pos = 1;
    
    while ((c = getchar()) != EOF) {
        // 可能出现\t \n 普通字符
        if (c == '\t') {
            do {
                putchar(' ');
            } while (tabpos(pos++, tab) != YES);
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            pos++;
        }
    }
}

// 确定pos是否位于制表符结束位上
int tabpos(int pos, char *tab) {
    if (pos > MAXLINE) {
        return YES;
    } else {
        return tab[pos];
    }
}


