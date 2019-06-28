//
//  8_5_fsize.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/28.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <stdlib.h>

#define NAME_MAX    14
#define PATH_MAX    1024

// Directory Entry
typedef struct {
    long ino;
    char name[NAME_MAX+1];
} Dirent_85;

// DIR
typedef struct {
    int fd;
    Dirent_85 d;
} DIR_85;

int main_8_5(int argc, char *argv[]) {
    return 0;
}

// fsize: print inode #, mode, links, size of file, filename
void fsize_8_5(char *name) {
    
}

// dirwalk: apply fcn to all files in dir
void dirwalk_85(char *dirname, void (*fcn)(char *)) {
    
}

// opendir: open a directory for readdir calls
DIR_85 *opendir_85(char *dirname) {
    int fd;
    struct stat stbuf;
    DIR_85 *dp;
    
    // 是否能正常打开
    // 是否能获取状态
    // 状态是否正常
    // 是否成功申请空间
    if ((fd = open(dirname, O_RDONLY, 0)) == -1
        || fstat(fd, &stbuf) == -1
        || (stbuf.st_mode & S_IFMT) != S_IFDIR
        || (dp = (DIR_85 *)malloc(sizeof(DIR_85))) == NULL) {
        return NULL;
    }
    dp->fd = fd;
    return dp;
}

// readdir: read directory entry in sequence
// local directory structure of mac os???
Dirent_85 *readdir_85(DIR_85 *dp) {
    return (Dirent_85 *) 0;
}

// closedir: close directory opened by opendir
void closedir_85(DIR_85 *dp) {
    
}
