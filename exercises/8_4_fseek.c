//
//  8_4_fseek.c
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
#define EOF_84      (-2)
#define NULL_84     0
#define BUFSIZE_84  1024
#define OPEN_MAX_84 20

enum _flags_84 {
    _READ_84   = 01,
    _WRITE_84  = 02,
    _UNBUF_84  = 04,
    _EOF_84    = 010,
    _ERR_84    = 020
};

typedef struct _iobuf_84 {
    int cnt;
    char *base;
    char *ptr;
    int flag;
    int fd;
} FILE_84;

FILE_84 _iob_84[OPEN_MAX_84] = {
    {0, (char *) 0, (char *) 0, _READ_84, 0},
    {0, (char *) 0, (char *) 0, _WRITE_84, 1},
    {0, (char *) 0, (char *) 0, _WRITE_84 | _UNBUF_84, 2},
};

#define stdin_84    (&_iob_84[0])
#define stdout_84   (&_iob_84[1])
#define stderr_84   (&_iob_84[2])

int main_8_4(int argc, char *argv[]) {
    return 0;
}

// fseek_84: seek with a file pointer
int fseek_84(FILE_84 *fp, long offset, int origin) {
    long rc = 0;
    unsigned long nc;
    
    // 在lseek基础上。。。
    // lseek返回文件中的新位置，出错时候返回-1；
    if (fp->flag & _READ_84) {
        // 当前模式为读，origin=1时候需要考虑缓冲区的那一段
        if (origin == 1) {
            offset -= fp->cnt;
        }
        rc = lseek(fp->fd, offset, origin);
    } else if (fp->flag & _WRITE_84) {
        // 当前模式为写，需要把缓冲区都写入文件
        if ((nc = fp->ptr - fp->base) > 0) {
            if (write(fp->fd, fp->base, nc) != nc) {
                rc = -1;
            }
        }
        if (rc != -1) {
            rc = lseek(fp->fd, offset, origin);
        }
    }
    return (rc == -1) ? -1 : 0;
}





