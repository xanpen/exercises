//
//  7_6_compare_files.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/23.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 100

void filecomp(FILE *, FILE *);

int main_7_6 (int argc, char *argv[]) {
    FILE *fp1, *fp2;
    
    if (argc != 3) {
        fprintf(stderr, "comp: need two file names\n");
        exit(1);
    } else {
        if ((fp1 = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "error: can not open %s\n", *argv);
        } else if ((fp2 = fopen(*++argv, "r")) == NULL) {
            fprintf(stderr, "error: can not open %s\n", *argv);
        } else {
            filecomp(fp1, fp2);
            fclose(fp1);
            fclose(fp2);
            exit(0);
        }
    }
    return 0;
}

// compare two files(a line at a time)
void filecomp(FILE *fp1, FILE *fp2) {
    char line1[MAXLINE];
    char line2[MAXLINE];
    
    char *lp1, *lp2;
    do {
        lp1 = fgets(line1, MAXLINE, fp1);
        lp2 = fgets(line2, MAXLINE, fp2);
        if (lp1 == line1 && lp2 == line2) {
            if ((strcmp(line1, line2)) != 0) {
                printf("first difference in line \n%s\n", line1);
                lp1 = lp2 = NULL;
            }
        } else if (lp1 != line1 && lp2 == line2) {
            fprintf(stderr, "end of the first file at line\n%s\n", line2);
        } else if (lp1 == line1 && lp2 != line2) {
            fprintf(stderr, "end of the second file at line \n%s\n", line1);
        }
    } while (lp1 == line1 && lp2 == line2);
}
