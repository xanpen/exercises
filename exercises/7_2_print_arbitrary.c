//
//  7_2_print_arbitrary.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/20.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXCHARS    30
#define OCTLEN      6

int main_7_2 (int argc, char *argv[]) {
    int c;
    int pos;
    int inc(int, int);
    
    pos = 0;
    while ((c = getchar()) != EOF) {
        if (iscntrl(c) || c == ' ') {
            pos = inc(pos, OCTLEN);
            // %3o :- 12-
            // %03o:-012-
            printf(" %03o ", c);
            
            if (c == '\n') {
                pos = 0;
                putchar('\n');
            }
        } else {
            pos = inc(pos, 1);
            putchar(c);
        }
    }
    return 0;
}

// increment position counter output
int inc(int pos, int n) {
    if (pos + n >= MAXCHARS) {
        putchar('\n');
        return n;
    } else {
        return pos + n;
    }
}
