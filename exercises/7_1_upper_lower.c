//
//  7_1_upper_lower.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/19.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main_7_1(int argc, char *argv[]) {
    int c;
    if (strcmp(argv[0], "upper") == 0) {
        while ((c = getchar()) != EOF) {
            putchar(toupper(c));
        }
    } else {
        while ((c = getchar()) != EOF) {
            putchar(tolower(c));
        }
    }
    return 0;
}
