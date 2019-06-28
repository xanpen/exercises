//
//  4_13_reverse.c
//  c_exercises
//
//  Created by wongxp on 2019/3/5.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>
/**
 *  recrisive version
 */
void reverse_recursive(char s[]) {
    void reverser(char [], int, int);
    int len = (int)strlen(s);
    int i = 0;
    
    reverser(s, i, len);
}

/**
 *  reverser
 *  0 1 2 3 4 5 6 7 8 9
 *  0+9=9 1+8=9 2+7=9 ... i+x=len-1 ===>  x=len-i-1
 *
 */
void reverser(char s[], int i, int len) {
    char temp;
    
    // 字符串交换首尾字符
    if (i < (len - i - 1)) {
        temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i -1] = temp;
        reverser(s, ++i, len);
    }
}
