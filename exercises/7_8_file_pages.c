//
//  7_8_file_pages.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/24.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE  100
#define MAXHDR   5
#define MAXBTM   3
#define MAXPAGE  66

void fileprint(FILE *, char *);

int main_7_8(int argc, char *argv[]) {
    FILE *fp;
    
    if (argc == 1) {
        fileprint(stdin, " ");
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "can not open %s\n", *argv);
            } else {
                fileprint(fp, *argv);
                fclose(fp);
            }
        }
    }
    return 0;
}

// 打印文件内容: 页头（2个空行+标题页码行+2个空行); 内容n行; 页脚（3个空行); 换页
void fileprint(FILE *fp, char *fname) {
    int heading(char *, int);
    char line[MAXLINE];
    int lineno = 1;
    int pageno = 1;
    // 页头
    lineno = heading(fname, pageno++);
    // 内容
    while (fgets(line, MAXLINE, fp) != NULL) {
        if (lineno == 1) {
            fprintf(stdout, "\t");
            heading(fname, pageno++);
        }
        
        fputs(line, stdout);
        if (++lineno > MAXPAGE - MAXBTM) {
            lineno = 1;
        }
    }
    fprintf(stdout, "\t");
}

// 填充页头
int heading(char *fname, int pageno) {
    int ln = 3;
    
    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s page %d\n", fname, pageno);
    // 最后指向第6行
    while (ln++ < MAXHDR) {
        fprintf(stdout, "\n");
    }
    return ln;
}











