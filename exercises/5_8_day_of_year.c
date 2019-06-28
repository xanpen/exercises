//
//  5_8_day_of_year.c
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
int day_of_year_5_8(int year, int month, int day) {
    int i, leap;
    
    if (year < 1) {
        return -1;
    }
    
    leap = ((year % 4 == 0 && year % 100 == 0) || year % 400 == 0);
    if (month < 1 || month > 12) {
        return -1;
    }
    if (day < 1 || day > daytab[leap][month]) {
        return -1;
    }
    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }
    return day;
}

// 根据一年中的第n天 设定 月和天
//
void month_day_5_8(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    
    leap = ((year % 4 == 0 && year % 100 == 0) || year % 400 == 0);
    
    for (i = 1; i <= 12 && yearday > daytab[leap][i]; i++) {
        yearday -= daytab[leap][i];
    }
    
    if (i > 12 || yearday > daytab[leap][12]) {
        *pmonth = -1;
        *pday = -1;
    } else {
        *pmonth = i;
        *pday = yearday;
    }
}
