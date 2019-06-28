//
//  3_3_expand.c
//  c_exercises
//
//  Created by wongxp on 2019/1/29.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
/// a-z0-9  A-Z   a-b-c
/// 很巧妙.......
void expand(char s1[], char s2[]) {
    int i, j;
    int c;
    for (i = j = 0; (c = s1[i++]) != '\0';) {
        if (s1[i] == '-' && s1[i+1] >= c) {
            ++i;
            while (s1[i] > c) {
                s2[j++] = c++;
            }
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}
