//
//  calculator.h
//  c_exercises
//
//  Created by 王显朋 on 2019/3/2.
//  Copyright © 2019年 wongxp. All rights reserved.
//

#ifndef calculator_h
#define calculator_h

#define NUMBER '0'
#define NAME 'n'

int getch(void);
void ungetch_(int);
void push(double);
double pop(void);
void clear_(void);

int getop(char []);
int getop_4_3(char []);
int getop_4_5(char []);
void mathfnc(char []);
int getop_4_6(char []);
int getop_4_10(char []);
int getop_4_11(char []);

void calc(void);
void calc_4_3(void);
void calc_4_4(void);
void calc_4_5(void);
void calc_4_6(void);
void calc_4_10(void);
void calc_4_11(void);

int getline_v2(char [], int);

#endif /* calculator_h */

