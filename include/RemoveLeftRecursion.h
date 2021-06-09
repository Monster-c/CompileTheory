//
// Created by cw on 2021/6/8.
//

#ifndef COMPILEEX_REMOVELEFTRECURSION_H
#define COMPILEEX_REMOVELEFTRECURSION_H

/**
 * 组织产生式
 * */
typedef struct P {
    char key;           // 产生式左部
    char *value[16];  // 产生式右部
    int count;          // 几组规则
} P;

/**
 * 文法的集合
 * */
typedef struct G {
    char *vn;     // 非终结符集合
    char *vt;     // 终结符集合
    P p[16];      // 产生式
    char start;     // 开始符号
    int pcount;
} G;

/**
 * 消除文法左递归
 * */
int RemoveLeftRecursion();

#endif //COMPILEEX_REMOVELEFTRECURSION_H
