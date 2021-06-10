//
// Created by cw on 2021/6/10.
//

#ifndef COMPILEEX_OPERATOR_PRIOR_H
#define COMPILEEX_OPERATOR_PRIOR_H

#include "./utils.h"


#define MAX 507
/**
 * 算符优先表的构造
 * */

//TODO:对代码的规范性再进行检查

/**
 * 保存输入的文法
 * */
class WF {
public:
    string left;
    vector<string> right;

    explicit WF(const string &str) {
        left = str;
    }

    //末尾追加
    void insert(char str[]) {
        right.emplace_back(str);
    }

    void print() {
        printf("%s->%s", left.c_str(), right[0].c_str());
        for (int i = 1; i < right.size(); i++)
            printf("|%s", right[i].c_str());
        puts("");
    }
};

/**
 * @brief:构建FIRSTVT集合
 * */
void make_firstvt();

/**
 * @brief:构建LASTVT集合
 * */
void make_lastvt();

/**
 * @brief:生成算符优先表
 * */
void make_operator_prior_table();

/**
 * @brief:入口函数
 * */
void make_it();

#endif //COMPILEEX_OPERATOR_PRIOR_H
