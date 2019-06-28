//
//  7_9_isupper.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/24.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#define isupper(c) ((c)>='A' && (c)<='Z') ? 1:0

int main_7_9(int argc, char *argv[]) {
    char *p = "This is a test";
    char c;
    
    if (isupper(c = *p)) {
        printf("%c\n", c);
        p++;
    } else {
        printf("err");
    }
    
    return 0;
}
