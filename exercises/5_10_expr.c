//
//  5_9_expr.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/1.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculator.h"
#include "exercises.h"

#define MAXOP 100

// 逆波兰计算器（command line方式）
int main5_10(int argc, char *argv[]) {
    
    char s[MAXOP];
    double op2;
    while (--argc > 0) {
        // 向输入缓冲区塞入命令行参数（后面带一个空格作为参数结束符，这样可以复用getop函数）
        ungets(" ");
        ungets(*++argv);
        // 从输入缓冲区读取一个操作数或者操作符
        switch (getop(s)) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 == 0.0) {
                    printf("error: zero divisor \n");
                } else {
                    push(pop() / op2);
                }
                break;
                
            default:
                argc = 1;
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    printf("%.8g\n", pop());
    return 0;
}
