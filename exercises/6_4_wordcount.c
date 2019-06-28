//
//  6_4_wordcount.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/17.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD     100
#define NDISTINCT   1000

struct tnode *talloc(void);
char *strdup_6_2(char *);
int getword_6_3(char *, int);

void sortlist(void);
struct tnode *addtreex_6_4(struct tnode *, char *);
void treestore(struct tnode *);

// 树结构
struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *list[NDISTINCT];
int ntreenode = 0;

int main_6_4(int argc, char *argv[]) {
    char word[MAXWORD];
    struct tnode *root = NULL;
    int i;
    
    while (getword_6_3(word, MAXWORD) != EOF) {
        //if (isalpha(word[0])) {
            root = addtreex_6_4(root, word);
        //}
    }
    treestore(root);
    sortlist();
    for (i = 0; i < ntreenode; i++) {
        printf("%2d:%20s\n", list[i]->count, list[i]->word);
    }
    return 0;
}

// addtreex_6_4
struct tnode *addtreex_6_4(struct tnode *p, char *word) {
    int cond;
    if (p == NULL) {
        p = talloc();
        p->count = 1;
        p->word = strdup(word);
        p->left = p->right = NULL;
    } else if ((cond = strcmp(word, p->word)) == 0) {
        p->count++;
    } else if (cond < 0) {
        p->left = addtreex_6_4(p->left, word);
    } else if (cond > 0) {
        p->right = addtreex_6_4(p->right, word);
    }
    return p;
}

// store in list[] pointers to tnode
void treestore(struct tnode *p) {
    if (p != NULL) {
        treestore(p->left);
        if (ntreenode < NDISTINCT) {
            list[ntreenode++] = p;
        }
        treestore(p->right);
    }
}

// sort list of pointers to tnodes
// shell sort
void sortlist(void) {
    int i, j;
    int gap;
    struct tnode *temp;
    
    for (gap = ntreenode/2; gap > 0; gap /= 2) {
        for (i = gap; i < ntreenode; i++) {
            if (list[i]->count < list[i-gap]->count) {
                for (j = i-gap; j >= 0 && list[j]->count > list[j+gap]->count; j -= gap) {
                    temp = list[j];
                    list[j] = list[j+gap];
                    list[j+gap] = temp;
                }
            }
        }
    }
}




