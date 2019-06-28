//
//  8_1_cat.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/25.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <fcntl.h>

void filecopy_8_1(int, int);
void error_8_1(char *, ...);

// cat: concatenate files, low level i/o version
int main_8_1 (int argc, char *argv[]) {
    int fd;
    
    char c;
    c = getc(stdin);
    printf("%c", c);
    putc('x', stdout);
    printf("-----%c,%c\n",getc(stdin), getc(stdin));
    
    
    if (argc == 1) {
        filecopy_8_1(0, 1);
    } else {
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
                error_8_1("cat: cant open %s", *argv);
            } else {
                filecopy_8_1(fd, 1);
                close(fd);
            }
        }
    }
    
    return 0;
}
// copy file ifd to ofd
void filecopy_8_1(int ifd, int ofd) {
    char buf[BUFSIZ];
    long n;
    
    while ((n = read(ifd, buf, BUFSIZ)) > 0) {
        if ((write(ofd, buf, n)) != n) {
            error_8_1("cat: write error!");
        }
    }
}
// error printf
void error_8_1(char *fmt, ...) {
    va_list args;
    
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}





