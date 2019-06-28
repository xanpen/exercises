//
//  4_qsort.c
//  c_exercises
//
//  Created by wongxp on 2019/3/4.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include "4_qsort.h"

/**
 *  quick sort version 1.0
 **/
void qsort1(int s[], int left, int right) {
    if (left < right) {
        int i, j, x;
        i = left;
        j = right;
        swap1(s, left, (left + right) / 2);
        // 第一次挖坑
        x = s[i];
        while (i < j) {
            // 从后向前遍历，寻找小于等于x的元素
            while (i < j && s[j] > x) {
                j--;
            }
            // 把从后向前找到的元素挖坑填数
            if (i < j) {
                s[i++] = s[j];
            }
            // 从前向后遍历，寻找大于x的元素
            while (i < j && s[i] <= x) {
                i++;
            }
            // 把从前向后找到的元素挖坑填数
            if(i < j) {
                s[j--] = s[i];
            }
        }
        // 此时i=j,最后一次填数
        s[i] = x;
        //递归
        qsort1(s, left, i - 1);
        qsort1(s, i + 1, right);
    }
}

/**
 *  quick sort version 2.0
 */
void qsort2(int v[], int left, int right) {
    if (left < right) {
        int i, last;
        swap1(v, left, (left + right) / 2);
        // 基准
        last = left;
        // 分区：小于基准的来左侧，大于基准的去右侧
        for (i = left + 1; i <= right; i++) {
            if (v[i] < v[left]) {
                swap1(v, i, ++last);
            }
        }
        // 基准复位
        swap1(v, left, last);
        qsort2(v, left, last - 1);
        qsort2(v, last + 1, right);
    }
}

/**
 *  swap
 */
void swap1(int v[], int i, int j) {
    int temp;
    if (i != j) {
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}
