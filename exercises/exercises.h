//
//  exercises.h
//  c_exercises
//
//  Created by 王显朋 on 2019/3/2.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#ifndef exercises_h
#define exercises_h

void squeeze(char [], char []);
int any(char [], char []);
int any_v2(char [], char []);

unsigned setbits(unsigned, int, int, unsigned);
unsigned invert(unsigned, int, int);

unsigned rightrot(unsigned, int);
unsigned rightrot_v2(unsigned, int);

int bitcount(unsigned);
int bitcount_v2(unsigned);

void lowerstr(char []);
int bitsearch(int, int [], int);
int bitsearch_old(int, int [], int);

void escape(char [], char []);
void unescape(char [], char []);
void unescape_v2(char [], char []);

void expand(char [], char []);
void itoa(int, char []);
void itoa_v2(int, char []);
void itoa_width(int, char [], int);
void itob(int, char [], int);

int getline_v2(char [], int);
int strrindex_v1(char [], char []);
int strrindex_v2(char [], char []);

double atof_extend(char []);

void ungets(char []);

void atoa_recursive(int, char []);
void reverse_recursive(char []);

int getint_5_1(int *);
int getfloat_5_2(double *);
void strcat_5_3(char *, char *);
int strend_5_4(char *, char *);
void strncpy_5_5(char *, char *, int n);
void strncpy_5_5_2(char *, char *, int n);
void strncat_5_5(char *, char *, int n);
int strncmp_5_5(char *, char *, int n);
int getline_5_6(char *, int);
int atoi_5_6(char *);

int day_of_year_5_8(int, int, int);
int day_of_year_5_9(int, int, int);
void month_day_5_8(int, int, int *, int *);
void month_day_5_9(int, int, int *, int *);

void error(char *);

int readlines_5_14(char *lineptr[], int);
void writelines_5_14(char *lineptr[], int, int);
int numcmp_5_14(char *s1, char *s2);
int strcmp_5_14(char *s1, char *s2);
void qsort_5_14(void *v[], int, int, int (*comp)(void *, void *));

int charcmp_5_15(char *, char *);
int charcmp_5_16(char *, char *);

void readargs(int, char *argv[]);
int numcmp_5_17(char *, char *);
int charcmp_5_17(char *, char *);
void substr_5_17(char *, char *, int);

void dcl(void);
void dirdcl(void);
int gettoken(void);
int nexttoken(void);
void errormsg(char *);

int getword(char *, int);

#endif /* exercises_h */
