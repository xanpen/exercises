//
//  4_1_strrindex.c
//  c_exercises
//
//  Created by wongxp on 2019/2/25.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int strrindex_v1(char s[], char t[]) {
    int i, j, k;
    int pos = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            pos = i;
        }
    }
    return pos;
}

int strrindex_v2(char s[], char t[]) {
    int i, j, k;
    for (i = (int)(strlen(s) - strlen(t)); i >= 0; i--) {
        for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++) {
            ;
        }
        if (k >=0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}

//getline_v2
int getline_v2(char line[], int lim) {
    int i, c;
    
    i = 0;
    c = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    
    return i;
}
