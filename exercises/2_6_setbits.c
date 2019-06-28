//
//  2_6_setbits.c
//  c_exercises
//
//  Created by 王显朋 on 2019/1/23.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

/// returns x with n-bits that begins at position p of x set to the rightmost n-bits of y;
/// xxxxnnxx 00000011  00001100  11110011  xxxx00xx
/// yyyyyynn 00000011  000000nn  0000nn00

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    
    return (~(~(~0 << n) << (p - n + 1)) & x) | (~(~0 << n) & y) << (p - n + 1);
}
