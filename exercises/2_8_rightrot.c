//
//  2_8_rightrot.c
//  c_exercises
//
//  Created by 王显朋 on 2019/1/24.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

/// 循环右移
unsigned rightrot(unsigned x, int n) {
    int wordlength(void);
    int rightmost_bit;
    
    while (n-- > 0) {
        /// 先取出x最后一位；左移63位（如果子长是64的话），结果是x最后一位跑到最左端，其余位都是0。
        rightmost_bit = (x & 1) << (wordlength() - 1);
        /// x右移一位
        x >>= 1;
        /// 把之前存好的rightmost_bit塞到x最左位。
        x |= rightmost_bit;
    }
    return x;
}

/// 循环右移v2
unsigned rightrot_v2(unsigned x, int n) {
    int wordlength(void);
    int rightmost_bit;
    
    /// 通过取余保证n在1~63之内
    if ((n %= wordlength()) > 0) {
        /// 取到x的最右端n位，其余位为0。
        rightmost_bit = ~(~0 << n) & x;
        /// 把rightmost_bit最右端n位移到最左端。
        rightmost_bit <<= (wordlength() - n);
        /// x直接右移n位。
        x >>= n;
        /// 用rightmost_bit填充x最左端n位。
        x |= rightmost_bit;
    }
    return x;
}

/// 计算机器wordlength
int wordlength(void) {
    int i;
    unsigned n = (unsigned)(~0);
    
    for (i = 1; (n >>= 1) > 0; i++) {
        ;
    }
    return i;
}
