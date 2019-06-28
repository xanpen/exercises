//
//  8_3.c
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
#define EOF_83      (-2)
#define NULL_83     0
#define BUFSIZE_83  1024
#define OPEN_MAX_83 20

enum _flags_83 {
    _READ_83   = 01,
    _WRITE_83  = 02,
    _UNBUF_83  = 04,
    _EOF_83    = 010,
    _ERR_83    = 020
};

typedef struct _iobuf_83 {
    int cnt;
    char *base;
    char *ptr;
    int flag;
    int fd;
} FILE_83;

FILE_83 _iob_83[OPEN_MAX_83] = {
    {0, (char *) 0, (char *) 0, _READ_83, 0},
    {0, (char *) 0, (char *) 0, _WRITE_83, 1},
    {0, (char *) 0, (char *) 0, _WRITE_83 | _UNBUF_83, 2},
};

#define stdin_83    (&_iob_83[0])
#define stdout_83   (&_iob_83[1])
#define stderr_83   (&_iob_83[2])

int main_8_3(int argc, char *argv[]) {
    return 0;
}

// 分配 刷新缓冲区;返回写入的字符
int _flushbuf_83(int x, FILE_83 *fp) {
    int bufsize;
    unsigned long nc;
    
    // 验证指针有效性
    if (fp < _iob_83 || fp >= _iob_83 + OPEN_MAX_83) {
        return EOF_83;
    }
    // 验证打开模式
    if ((fp->flag & (_WRITE_83 | _ERR_83)) != _WRITE_83) {
        return EOF_83;
    }
    bufsize = (fp->flag & _UNBUF_83) ? 1 : BUFSIZ;
    // 分配空间
    if (fp->base == NULL) {
        if ((fp->base = (char *)malloc(bufsize)) == NULL) {
            fp->flag |= _ERR_83;
            return EOF_83;
        }
    } else {
        nc = fp->ptr - fp->base;
        if (write(fp->fd, fp->base, nc) != nc) {
            fp->flag |= _ERR_83;
            return EOF_83;
        }
    }
    fp->ptr = fp->base;
    *fp->ptr++ = x;
    fp->cnt = bufsize - 1;
    return x;
}
// 刷新缓冲区
int _fflush_83(FILE_83 *fp) {
    int rc = 0;
    int _flushbuf_83(int, FILE_83 *);
    
    if (fp < _iob_83 || fp >= _iob_83 + OPEN_MAX_83) {
        return EOF_83;
    }
    if (fp->flag & _WRITE_83) {
        rc = _flushbuf_83(0, fp);
    }
    fp->ptr = fp->base;
    fp->cnt = (fp->flag & _UNBUF_83) ? 1 : BUFSIZ;
    return rc;
}
// 关闭文件
int _fclose_83(FILE_83 *fp) {
    int rc;
    int _fflush_83(FILE_83 *);
    
    if ((rc = fflush(fp)) != EOF_83) {
        free(fp->base);
        //close(fp->fd);
        fp->base = NULL_83;
        fp->ptr = NULL_83;
        fp->cnt = 0;
        fp->flag &= ~(_READ_83 | _WRITE_83);
    }
    return rc;
}
