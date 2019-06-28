//
//  6_2_addtreex.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/13.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100
#define YES     1
#define NO      0

// struct tree node
struct tnode{
    char *word;
    int match;
    struct tnode *left;
    struct tnode *right;
};

int compare_6_2(char *, struct tnode *, int, int *);
struct tnode *talloc(void);
char *strdup_6_2(char *);
void treexprint(struct tnode *);
struct tnode *addtreex(struct tnode *, char *, int, int *);
int getword(char *, int);

// print in alphabetic order each group of variable names
// identical in the first num characters
int main_6_2(int argc, char *argv[]) {
 
    char word[MAXWORD];
    int num;
    int found = NO;
    struct tnode *root;
    root = NULL;
    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1): 4;
    
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && strlen(word) >= num) {
            root = addtreex(root, word, num, &found);
        }
        found = NO;
    }

    treexprint(root);
    return 0;
}

// talloc: make a tnode
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

// strdup_6_2: make a duplicate of s
char *strdup_6_2(char *s) {
    char *p = (char *) malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    
    return p;
}

// add a node with w at or below p
struct tnode *addtreex(struct tnode *p, char *word, int num, int *found) {
    int cond;
    if (p == NULL) {
        p = talloc();
        p->word = strdup_6_2(word);
        p->match = *found;
        p->left = p->right = NULL;
    } else if ((cond = compare_6_2(word, p, num, found)) < 0) {
        p->left = addtreex(p->left, word, num, found);
    } else if (cond > 0) {
        p->right = addtreex(p->right, word, num, found);
    }
    
    return p;
}

// compare words and update p->match
int compare_6_2(char *s, struct tnode *p, int num, int *found) {
    char *t = p->word;
    int i;
    
    for (i = 0; *s == *t; i++, s++, t++) {
        if (*s == '\0') {
            return 0;
        }
    }
    
    if (i >= num) {
        *found = YES;
        p->match = YES;
    }
    
    return *s - *t;
}

// treexprint: in-order print of tree p if p->match is true
void treexprint(struct tnode *p){
    if (p != NULL) {
        treexprint(p->left);
        if (p->match) {
            printf("%s\n", p->word);
        }
        treexprint(p->right);
    }
}
