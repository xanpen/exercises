//
//  8_6_calloc.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/29.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main_86(int argc, char *argv[]) {
    
    int a = 5;
    int *x = &a;
    
    printf("%d", *x++);
    printf("%d", a);
    
    struct a {
        short si;
        int i;
        char c;
    };
    union header {
        struct a s;
        int x;
        unsigned y;
    };
    //printf("%lu\n", sizeof(union header));

    return 0;
}
