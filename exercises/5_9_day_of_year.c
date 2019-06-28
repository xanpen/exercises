//
//  5_9_day_of_year.c
//  c_exercises
//
//  Created by 王显朋 on 2019/4/1.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>

// 一年中每个月（闰月 非闰月）的天数
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// 根据 月和天 设定一年中的第n天
// 1999 6 5
int day_of_year_5_9(int year, int month, int day) {
    int leap;
    char *p;
    
    leap = ((year % 4 == 0 && year % 100 == 0) || year % 400 == 0);
    p = daytab[leap];
    
    while (--month) {
        day += *++p;
    }
    return day;
}

// 根据一年中的第n天 设定 月和天
//
void month_day_5_9(int year, int yearday, int *pmonth, int *pday) {
    int leap;
    char *p;
    
    leap = (year % 4 == 0 && year % 100 == 0) || year % 400 == 0;
    p = daytab[leap];
    
    while (yearday > *++p) {
        yearday -= *p;
    }
    *pmonth = (int)(p - *(daytab + leap));
    *pday = yearday;
}
