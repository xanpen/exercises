//
//  insert_srot.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/17.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

void insert_sort(char *, int);
void swap_sort(char *, int);
void shell_sort_v1(char *, int);
void shell_sort_v2(char *, int);

int main_sort(int argc, char *argv[]) {
    char s[] = {
        4,3,2,6,1,5
    };
    //insert_sort(s, 6);
    //swap_sort(s, 6);
    //shell_sort_v1(s, 6);
    shell_sort_v2(s, 6);
    int i;
    for (i = 0; i < 6; i++) {
        printf("%d\n", s[i]);
    }
    return 0;
}
// 简单交换排序
void swap_sort(char *s, int lim) {
    char temp;
    int i;
    int j;
    
    for (i = 1; i < lim; i++) {
        if (s[i] < s[i -1]) {
            for (j = i - 1; j >= 0 && s[j + 1] < s[j]; j--) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

// 简单插入排序
// 分为有序集合和无序集合。遍历无序集合中的元素插入到有序集合中的正确位置。
//
void insert_sort(char *s, int lim) {
    char last;
    int i;
    int j;
    
    // 初始认为集合(s[0]...)有序集合；集合（s[1]...s[n-1]）无序集合
    for (i = 1; i < lim; i++) {
        //
        if (s[i] < s[i - 1]) {
            last = s[i];
            for (j = i - 1; j >= 0 && s[j] > last; j--) {
                s[j + 1] = s[j];
            }
            s[j+1] = last;
        }
    }
}

// 希尔排序
// 分组执行插入排序
// 当gap=1分成一组的时候，集合已经高度有序，此时插入排序效率很高。
void shell_sort_v1(char s[], int lim) {
    int i, j;
    int temp;
    int gap;
    
    for (gap = lim/2; gap > 0; gap /= 2) {
        for (i = gap; i < lim; i++) {
            if (s[i] < s[i - gap]) {
                for (j = i - gap; j >= 0 && s[j] > s[j + gap]; j -= gap) {
                    temp = s[j];
                    s[j] = s[j+gap];
                    s[j+gap] = temp;
                }
            }
        }
    }
}
void shell_sort_v2(char *s, int lim) {
    int i, j;
    int gap;
    int last;
    
    for (gap = lim/2; gap > 0; gap /= 2) {
        // 轮流对分组执行插入排序
        for (i = gap; i < lim; i++) {
            if (s[i] < s[i - gap]) {
                last = s[i];
                for (j = i - gap; j >= 0 && s[j] > last; j -= gap) {
                    s[j + gap] = s[j];
                }
                s[j + gap] = last;
            }
        }
    }
}













