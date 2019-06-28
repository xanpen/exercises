//
//  2_4_squeeze.c
//  c_exercises
//
//  Created by wongxp on 2019/1/22.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

// s1 = "abcde"; s2 = "bd"; squeeze(s1, s2); s1 = "ace";
void squeeze(char s1[], char s2[]) {
    int i, j, k;
    for (i = j = 0; s1[i] != '\0'; ++i) {
        for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; ++k) {
            ;
        }
        if (s2[k] == '\0') {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}
