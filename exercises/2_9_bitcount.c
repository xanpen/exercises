//
//  bitcount.c
//  c_exercises
//
//  Created by wongxp on 2019/1/24.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

int bitcount(unsigned x) {
    int num;
    for (num = 0; x > 0; x >>= 1) {
        if (x & 1) {
            num++;
        }
    }
    return num;
}
/// x 中位为1的个数
/// 利用了结论：x & (x - 1) 会清除x最右端值为1的位。
int bitcount_v2(unsigned x) {
    int num;
    for (num = 0; x > 0; x &= (x - 1)) {
        num++;
    }
    return num;
}
