//
//  6_3_cross_referencer.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/16.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculator.h"

#define MAXWORD   100

struct tnode *talloc(void);
char *strdup_6_2(char *);

struct tnode *addtreex_6_3(struct tnode *, char *, int);
void addlink(struct tnode *, int);
struct linklist *lalloc(void);
void treexprint_6_3(struct tnode *);
int noiseword(char *);
int getword_6_3(char *, int);


// 链表结构
struct linklist {
    int linenum;
    struct linklist *ptr;
};

// 树结构
struct tnode {
    char *word;
    struct linklist *lines;
    struct tnode *left;
    struct tnode *right;
};

int main_6_3(int argc, char *argv[]) {
    char word[MAXWORD];
    int linenum = 1;
    struct tnode *root = NULL;
    
    while (getword_6_3(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && noiseword(word) == -1) {
            root = addtreex_6_3(root, word, linenum);
        } else if (word[0] == '\n') {
            linenum++;
        }
    }
    treexprint_6_3(root);
    return 0;
}

// addtreex_6_3: 在p节点或者p节点下面添加一个节点
struct tnode *addtreex_6_3(struct tnode *p, char *word, int linenum) {
    int cond;
    
    if (p == NULL) {
        p = talloc();
        p->word = strdup_6_2(word);
        p->lines = lalloc();
        p->lines->linenum = linenum;
        p->lines->ptr = NULL;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(word, p->word)) == 0) {
        addlink(p, linenum);
    } else if (cond < 0) {
        p->left = addtreex_6_3(p->left, word, linenum);
    } else if (cond > 0) {
        p->right = addtreex_6_3(p->right, word, linenum);
    }
    return p;
}

// 添加一个节点到链表上
// 当新单词已经存在于树上时，需要把该单词的行号加到其链表上（如果行号不同的话）
void addlink(struct tnode *p, int linenum) {
    struct linklist *temp = p->lines;
    
    while (temp->ptr != NULL && temp->linenum != linenum) {
        temp = temp->ptr;
    }
    
    if (temp->linenum != linenum) {
        temp->ptr = lalloc();
        temp->ptr->linenum = linenum;
        temp->ptr->ptr = NULL;
    }
}

// 打印树
void treexprint_6_3(struct tnode *p) {
    struct linklist *temp;
    if (p != NULL) {
        
        treexprint_6_3(p->left);
        printf("%10s: ", p->word);
        for (temp = p->lines; temp != NULL; temp = temp->ptr) {
            printf("%4d ", temp->linenum);
        }
        printf("\n");
        treexprint_6_3(p->right);
    }
}

// lalloc:  make a linklist node
struct linklist *lalloc(void) {
    return (struct linklist *)malloc(sizeof(struct linklist));
}

// 二分查找“噪音词”
int noiseword(char *word) {
    static char *nw[] = {
        "a",
        "an",
        "and",
        "are",
        "in",
        "is",
        "of",
        "or",
        "that",
        "the",
        "this",
        "to"
    };
    
    int cond;
    int low = 0;
    int mid;
    int high = sizeof(nw) / sizeof(char *) - 1;
    
    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(word, nw[mid])) < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

// get next word or character from input
int getword_6_3(char *word, int lim) {
    int c;
    char *w = word;
    
    while (isspace(c = getch()) && c != '\n') {
        ;
    }
    if (c != EOF) {
        *w++ = c;
    }
    
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch_(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}
