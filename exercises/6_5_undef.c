//
//  6_5_undef.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/18.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define HASHSIZE    100

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);

int main_6_5(int argc, char *argv[]) {
    // test
    
    return 0;
}

// 链表结构
struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

// hash: form hash value for string s
unsigned hash(char *s) {
    unsigned hashval;
    
    for (hashval = 0; *s != '\0'; s++) {
        hashval = *s + (31 * hashval);
    }
    return hashval % HASHSIZE;
}

// undef: remove a name and definition from the table
void undef(char *s) {
    struct nlist *np;
    struct nlist *prev = NULL;
    unsigned hashval = hash(s);
    
    for (np = hashtab[hashval]; np != NULL; np = np->next) {
        if (strcmp(s, np->name) == 0) {
            break;
        }
        // 保存前一个节点指针
        prev = np;
    }
    // np!=null 说明s在table中
    if (np != NULL) {
        // prev=null 说明np指向链表开始位置
        if (prev == NULL) {
            hashtab[hashval] = np->next;
        } else {
            prev->next = np->next;
        }
        free((void *)np->name);
        free((void *)np->defn);
        free((void *)np);
    }
}






