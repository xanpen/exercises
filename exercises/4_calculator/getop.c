//
//  getop.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/2.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include "calculator.h"

/**
 *  get next operator or numeric oprand
 */
int getop(char s[]) {
    int i, c;
    // 过滤空格和tab
    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    // 收集操作符：如果是非数字非小数点，保证字符串s完整
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;
    }
    // 收集操作数
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    // 收集操作数（小数点部分）
    if (c == '.') {
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    // 因为s[i]此时储存的是非数字非小数点，所以直接以为\0覆盖掉
    s[i] = '\0';
    // 是否需要压回input输入缓冲区
    if (c != EOF) {
        ungetch_(c);
    }
    
    return NUMBER;
}
