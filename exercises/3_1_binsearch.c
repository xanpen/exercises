//
//  3_1_binsearch.c
//  c_exercises
//
//  Created by wongxp on 2019/1/28.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
///
int bitsearch(int x, int v[], int n) {
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    
    while (low <= high && x != v[mid]) {
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    
    if (x == v[mid]) {
        return mid;
    } else {
        return -1;
    }
}

/// More readable.
int bitsearch_old(int x, int v[], int n) {
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    
    while (low <= high) { 
        mid = (low + high) / 2;
        if (x < v[mid]) {
            high = mid - 1;
        } else if (x > v[mid]) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    
    return -1;
}
