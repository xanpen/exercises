//
//  2_5_any.c
//  c_exercises
//
//  Created by wongxp on 2019/1/22.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

/// s1 = "abcde123f";
/// s2 = "xxx2yyy";
/// 6
int any(char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return  i;
            }
        }
    }
    return -1;
}

/// s1 = "abced123f";
/// s2 = "123";
/// 5
int any_v2(char s1[], char s2[]) {
    int i, j, k;
    for (i = 0; s1[i] != '\0'; ++i) {
        for (k = 0,j = i; s2[k] != '\0' && s2[k++] == s1[j++]; ) {
            ;
        }
        if (k > 0 && s2[k] == '\0') {
            return i;
        }
    }
    
    return -1;
}
