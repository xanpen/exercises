//
//  3_2_escape.c
//  c_exercises
//
//  Created by wongxp on 2019/1/28.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

/// escape
void escape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\n'; ++i) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}
/// unescape
void unescape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; ++i) {
        if (t[i] != '\\') {
            s[j++] = t[i];
        } else {
            switch (s[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                default:
                    // 例如：b;需把\b原样复制过去
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
        }
    }
    s[j] = '\0';
}
/// unescape_v2
void unescape_v2(char s[], char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; ++i) {
        switch (s[i]) {
            case '\\':
                switch (s[++i]) {
                    case 'n':
                        s[j++] = '\n';
                        break;
                        
                    case 't':
                        s[j++] = '\t';
                        break;
                        
                    default:
                        s[j++] = '\\';
                        s[j++] = t[i];
                        break;
                }
                
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}
