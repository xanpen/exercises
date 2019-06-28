//
//  6_1_getword.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/11.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include "exercises.h"
#include "calculator.h"

int main_6_1(int argc, char *argv[]) {
    char word[100];
    while (getword(word, 100) != EOF) {
        printf("%s\n", word);
    }
    return 0;
}

// get next word or character from the input
int getword(char *word, int lim) {
    int comment(void);
    int c, d;
    char *w = word;
    
    while (isspace(c = getch())) {
        ;
    }
    
    if (c != EOF) {
        *w++ = c;
    }
    
    if (isalpha(c) || c == '_' || c == '#') {
        for (; --lim > 0;w++) {
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch_(*w);
                break;
            }
        }
    } else if (c == '"' || c == '\'') {
        for (; --lim > 0; w++) {
            if ((*w = getch()) == '\\') {
                *++w = getch();
            } else if (*w == c) {
                w++;
                break;
            } else if (*w == EOF) {
                break;
            }
        }
    } else if (c == '/') {
        if ((d = getch()) == '*') {
            c = comment();
        } else {
            ungetch_(d);
        }
    }
    *w = '\0';
    
    return c;
}

// skip over comment and return a character
int comment(void) {
    int c;
    while ((c = getch()) != EOF) {
        if (c == '*') {
            if ((c = getch()) == '/') {
                break;
            } else {
                ungetch_(c);
            }
        }
    }
    return c;
}
