//
//  main.c
//  c_exercises
//
//  Created by 王显朋 on 2019/1/22.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "exercises.h"
#include "calculator.h"
#include "4_qsort.h"
#include "4_14_swap.h"
#define MAXLINE = 1000

#define dprint(expr) printf(#expr " = %g\n", expr)



int main(int argc, const char * argv[]) {
    
    // day_of_year
    printf("day_of_year (array version): %d,\n", day_of_year_5_8(2019, 4,1));
    printf("day_of_year (pointer version): %d,\n", day_of_year_5_9(2019, 4,1));
    int month58 = 0, month59 = 0, day58 = 0, day59 = 0;
    month_day_5_8(2019, 91, &month58, &day58);
    month_day_5_9(2019, 91, &month59, &day59);
    printf("month: %d, day: %d \n", month58, day58);
    printf("month: %d, day: %d \n", month59, day59);
    
    //atoi_5_6
    char s_atoi_56[100] = "  -234";
    printf("atoi_5_6: %d\n", atoi_5_6(s_atoi_56));
    
    //getline_5_6
    //char s56[100];
    //printf("getline_5_6: len:%d,string:%s\n", getline_5_6(s56, 100), s56);
    
    //strncmp_5_5
    char scmp55[] = "abcdeeee";
    char tcmp55[] = "abcdssss";
    printf("strncmp_5_5: %d\n", strncmp_5_5(scmp55, tcmp55, 5));
    
    //strncat_5_5
    char scat55[] = "abcdef";
    char tcat55[] = "123456";
    strncat_5_5(scat55, tcat55, 6);
    printf("strncat_5_5: %s\n", scat55);
    
    //strncpy_5_5_2
    char scpy55[] = "abcdef";
    char tcpy55[] = "123456";
    strncpy_5_5_2(scpy55, tcpy55, 70);
    printf("strcpy_5_5: %s\n", scpy55);
    
    //strend_5_4
    char s54[1000] = "123456abc";
    char t54[1000] = "123456abc";
    printf("strend_5_4: %d\n", strend_5_4(s54, t54));
    
    //strcat_5_3
    char s53[1000] = "this is";
    char t53[1000] =  " a test!";
    strcat_5_3(s53, t53);
    printf("strcat_5_3: %s\n", s53);
    
    /**
    int n;
    double arr[3];
    arr[0] = arr[1] = arr[2] = 0.0;
    for (n = 0; n < 3 && getfloat_5_2(&arr[n]) != EOF; n++) {
        ;
    }
    while (n-- > 0) {
        printf("float number: %g\n", arr[n]);
    }
    */
    
    //5_1 getint
    /*int n, array[10];
    for (n = 0; n < 10 && getint_5_1(&array[n]) != EOF; n++) {
        ;
    }
    while (n-- > 0) {
        printf("number: %d\n", array[n]);
    }*/
    
    // macro swap
    int swap_i = 12, swap_j = 13;
    swap(int, swap_i, swap_j);
    printf("macro swap: %d, %d\n", swap_i, swap_j);
    
    //recursion
    char s_recur[] = "";
    atoa_recursive(-12345, s_recur);
    printf("atoa_recursive: %s\n", s_recur);
    reverse_recursive(s_recur);
    printf("reverse_recursive: %s\n", s_recur);
    
    //quick sort
    int qs[] = {2,44,5,32,45,98,67,12,2,786};
    qsort2(qs, 0, 9);
    for (int qi = 0; qi < 10; qi++) {
        printf("qsort1: %d \n", qs[qi]);
    }
    printf("\n");
    
    
    // reverse polish calculator
    //calc_4_3();
    //calc_4_4();
    //calc_4_5();
    //calc_4_6();
    //calc_4_10();
    //calc_4_11();
    
    //4_2_atof_extend
    char s_aotf_extend[] = "   -123.456e-7  ";
    printf("atof_extend(-123.456e-3):%f\n", atof_extend(s_aotf_extend));
    
    //4_1_strrindex
    /*char line[1000];
    char pattern[] = "ould";
    while (getline_v2(line, 1000) > 0) {
        if (strrindex_v2(line, pattern) >= 0) {
            printf("match line: %s\n", line);
        }
    }*/
    
    /// itob()
    char itob_s[] = "";
    itob(-199, itob_s, 16);
    printf("itob:%s\n", itob_s);
    
    /// itoa_width()
    char itoa_width_s[] = "";
    itoa_width(123456789, itoa_width_s, 20);
    printf("itoa_width:%s\n", itoa_width_s);
    
    /// itoa()
    char itoa_s[] = "";
    itoa_v2(-999999999, itoa_s);
    printf("itoa:%s\n", itoa_s);
    
    ///expand()
    char expand_s1[] = "a-a-a-z";
    char expand_s2[] = "";
    expand(expand_s1, expand_s2);
    printf("expand:%s\n", expand_s2);
    /// escape() unescape()
    char s81[100];
    char s82[100];
    char t81[] = "this\tis\ta\ttest\nover\n";
    char t82[] = "hello\\t\\tworld\\n!";
    escape(s81, t81);
    unescape(s82, t82);
    printf("escape:%s\n", s81);
    printf("unescape:%s\n", s82);
    
    /// bitsearch()
    int i[10] = {0,1,2,3,4,5,6,7,8,9};
    printf("bitsearch:%d\n", bitsearch(5, i, 10));
    printf("bitsearch_old:%d\n", bitsearch_old(4, i, 10));
    /// lowerstr(s)
    char s7[] = "AbCDe";
    lowerstr(s7);
    printf("AbCDe:%s\n", s7);
    /// bitcount(255) 8
    /// bitcount_v2(255) 8
    printf("bitcount   :%d\n", bitcount(255));
    printf("bitcount_v2:%d\n", bitcount_v2(255));
    /// rightrot(1, 1)      80000000(32位机器结果)
    /// rightrot_v2(1, 1)   80000000(32位机器结果）
    printf("rightrot   :%x\nrightrot_v2:%x\n", rightrot(1, 1), rightrot_v2(1, 1));
    /// invert(x, p, n)  193
    printf("x:%d, p:%d, n:%d, result:%d\n", 205, 3, 2, invert(205, 3, 2));
    /// setbits(x, p, n, y) 201
    printf("x:%d, p:%d, n:%d, y:%d, result:%d\n", 205, 3, 2, 130, setbits(205, 3, 2, 130));
    
    /// any(s1, s2)
    char s5[] = "abcde123f";
    char s6[] = "xxx2yyy";
    printf("pos: %d\n", any(s5, s6));
    /// any_v2(s1, s2)
    char s3[] = "abcde123f";
    char s4[] = "123";
    printf("pos: %d\n", any_v2(s3, s4));
    /// squeeze(s1, s2)
    char s1[] = "what the fuck~";
    char s2[] = "fuck";
    printf("stirng s1 before squeeze : %s \n", s1);
    squeeze(s1, s2);
    printf("stirng s1 after squeeze : %s \n", s1);
    
    return 0;
}
