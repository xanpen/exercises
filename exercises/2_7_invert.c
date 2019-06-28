//
//  2_7_inert.c
//  c_exercises
//
//  Created by 王显朋 on 2019/1/24.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

/// Returns x with the n-bits that begins at position p inverted.
/// xxxxnnxx ^ 00001100  x位不变，n位翻转
/// xxxxnnxx ^ 11110011  x位翻转，n位不变
unsigned invert(unsigned x, int p, int n) {
    return (~(~0 << n) << (p - n + 1)) ^ x;
}
