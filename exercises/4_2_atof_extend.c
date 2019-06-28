//
//  4_2_atof_extend.c
//  c_exercises
//
//  Created by wongxp on 2019/2/26.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

double atof_extend(char s[]) {
    int i, sign, esign;
    double sum, power, esum;
    
    // 处理空格
    for (i = 0; isspace(s[i]); i++) {
        ;
    }
    // 处理符号
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
        i++;
    }
    // 处理小数点钱的数字
    for (sum = 0.0; isdigit(s[i]); i++) {
        sum = sum * 10.0 + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    // 处理小数点后的数字
    for (power = 1.0; isdigit(s[i]); i++) {
        sum = sum * 10.0 + (s[i] - '0');
        power *= 10.0;
    }
    sum = sign * sum / power;
    // 处理科学计数法
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        
        esign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+') {
            i++;
        }
        for (esum = 0; isdigit(s[i]); i++) {
            esum = esum * 10.0 + (s[i] - '0');
        }
        if (esign == -1) {
            while (esum-- > 0) {
                sum /= 10;
            }
        } else {
            while (esum-- > 0) {
                sum *= 10;
            }
        }
    }
    return sum;
}
