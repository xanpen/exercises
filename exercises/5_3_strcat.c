//
//  5_3_strcat.c
//  c_exercises
//
//  Created by 王显朋 on 2019/3/28.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

void strcat_5_3(char *s, char *t) {
    while (*s)
        s++;
    while ((*s++ = *t++))
        ;
}
