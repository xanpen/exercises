//
//  2_10_lower.c
//  c_exercises
//
//  Created by wongxp on 2019/1/24.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
// 字符转小写
int lower(char c) {
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}
// 字符串转小写
void lowerstr(char s[]) {
    int i;
    int lower(char c);
    
    for (i = 0; s[i] != '\0'; ++i) {
        s[i] = lower(s[i]);
    }
}
