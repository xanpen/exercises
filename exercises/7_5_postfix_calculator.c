//
//  7_5_postfix_calculator.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/21.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#define NUMBER  '0'

int main_7_5(int argc, char *argv[]) {
    
    return 0;
}

// [    45.34 ]
int getop_7_5_1(char *s) {
    static char lastc[] = " ";
    char c;
    int rc;
    int i;
    
    sscanf(lastc, "%c", &c); // 首先从静态缓冲区读取字符 && 然后清空缓冲区
    lastc[0] = ' '; // 清空缓冲区
    
    // 1,c=非空格字符:
    // 2,c=EOF
    while ((s[0] = c) == ' ' || c == '\t') {
        if (scanf("%c", &c) == EOF) {
            c = EOF;
        }
    }
    s[1] = '\0';
    // 操作符
    if (!isdigit(c) && c != '.') {
        return c;
    }
    
    // 操作数
    // 说明：1：c=非数字退出循环
    //      2: rc=eof退出循环，这时的scanf没有给c赋值
    i = 0;
    if (isdigit(c)) {
        do {
            rc = scanf("%c", &c);
            if (!isdigit(s[++i] = c)) {
                break;
            }
        } while (rc != EOF);
    }
    
    if (c == '.') {
        do {
            rc = scanf("%c", &c);
            if (!isdigit(s[++i] = c)) {
                break;
            }
        } while (rc != EOF);
    }
    
    // 如果rc不是EOF的话，塞回缓冲区；
    s[i] = '\0';
    if (rc != EOF) {
        lastc[0] = c;
    }
    
    return NUMBER;
}

// [    45.34 ]
int getop_7_5_2(char *s) {
    char c;
    int rc;
    float f;
    
    while ((rc = scanf("%c", &c)) != EOF) {
        if ((s[0] = c) != ' ' && c != '\t') {
            break;
        }
    }
    s[1] = '\0';
    // 在操作数或者操作符之前出现了EOF
    if (rc == EOF) {
        s[0] = '\0';
        return EOF;
    } else {
        // 操作符
        if (!isdigit(c) && c != '.') {
            return c;
        }
    }
    // c当前可能是数字和小数点，所以塞回输入缓冲区;开始收集操作数，
    ungetc(c, stdin);
    scanf("%f", &f);
    sprintf(s, "%f", f);
    
    return NUMBER;
}




