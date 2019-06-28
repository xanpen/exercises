//
//  5_4_strend.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/28.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

// s="123abc"
// t=  "4abc"
int strend_5_4(char *s, char *t) {
    char *ps = s;
    char *pt = t;
    while (*s)
        s++;
    while (*t)
        t++;
    for (; *s == *t; s--,t--) {
        if (s == ps || t == pt) {
            break;
        }
    }
    if (*s == *t && t == pt && *s != '\0') {
        return 1;
    } else {
        return 0;
    }
}
