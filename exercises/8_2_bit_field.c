//
//  8_2_bit_field.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/27.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define PERMS       0666
#define EOF_82      (-2)
#define NULL_82     0
#define BUFSIZE_82  1024
#define OPEN_MAX_82 20

typedef struct _iobuf_82 {
    int cnt;
    char *base;
    char *ptr;
    struct flag_field_82 {
        unsigned int is_read:  1;
        unsigned int is_write: 1;
        unsigned int is_buf:   1;
        unsigned int is_unfuf: 1;
        unsigned int is_eof:   1;
        unsigned int is_err:   1;
    } flag;
    int fd;
} FILE_82;

FILE_82 _iob_82[OPEN_MAX_82] = {
    {0, (char *) 0, (char *) 0, {1, 0, 1,0, 0, 0}, 0},
    {0, (char *) 0, (char *) 0, {0, 1, 1, 0, 0, 0}, 1},
    {0, (char *) 0, (char *) 0, {0, 1, 1, 1, 0, 0}, 2},
};

#define stdin_82    (&_iob_82[0])
#define stdout_82   (&_iob_82[1])
#define stderr_82   (&_iob_82[2])

int main_8_2(int argc, char *argv[]) {
    return 0;
}

// open file , return file pointer
FILE_82 *_fopen_82(char *name, char *mode) {
    FILE_82 *fp;
    int fd;
    
    // 不合法的mode
    if (*mode != 'r' || *mode != 'w' || *mode != 'a') {
        return NULL_82;
    }
    // find free slot
    for (fp = _iob_82; fp < _iob_82 + OPEN_MAX_82; fp++) {
        if (fp->flag.is_read == 0  && fp->flag.is_write == 0) {
            break;
        }
    }
    if (fp >= _iob_82 + OPEN_MAX_82) {
        return NULL_82;
    }
    // 生成file descriptor
    if (*mode == 'w') {
        fd = creat(name, PERMS);
    } else if(*mode == 'a') {
        if ((fd = open(name, O_WRONLY, 0)) == -1) {
            fd = creat(name, PERMS);
            lseek(fd, 0, 2);
        }
    } else {
        fd = open(name, O_RDONLY, 0);
    }
    if (fd == -1) {
        return NULL_82;
    }
    
    fp->cnt = 0;
    fp->fd = fd;
    fp->base = NULL_82;
    fp->flag.is_unfuf = 0;
    fp->flag.is_eof = 0;
    fp->flag.is_err = 0;
    fp->flag.is_buf = 1;
    if (*mode == 'r') {
        fp->flag.is_read = 1;
        fp->flag.is_write = 0;
    } else {
        fp->flag.is_write = 1;
        fp->flag.is_read = 0;
    }
    
    return fp;
}

// allocate and fill input buffer
int _filebuf_82(FILE_82 *fp) {
    int bufsize;
    
    if (fp->flag.is_read == 0 || fp->flag.is_eof == 1 || fp->flag.is_err == 1) {
        return EOF_82;
    }
    bufsize = (fp->flag.is_buf == 1) ? BUFSIZ : 1;
    // 分配buf
    if (fp->base == NULL_82) {
        if ((fp->base = malloc(bufsize)) == NULL_82) {
            return EOF_82;
        }
    }
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if (--fp->cnt < 0) {
        if (fp->cnt == -1) {
            fp->flag.is_eof = 1;
        } else {
            fp->flag.is_err = 1;
        }
        fp->cnt = 0;
        return EOF_82;
    }
    return (unsigned)*fp->ptr++;
}













