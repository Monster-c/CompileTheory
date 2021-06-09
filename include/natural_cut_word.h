//
// Created by cw on 2021/5/28.
//

#pragma once
#ifndef COMPILEEX_EX2_FH
#define COMPILEEX_EX2_FH

#include "utils.h"
#include "../include/PreProcess.h"

//保留字表
static char RESERVE_TABLE[32][20] = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long",
        "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
};
//运算符、界符
static char OPERATOR_OR_DELIMITER[36][10] = {
        "+", "-", "*", "/", "<", "<=", ">", ">=", "=", "==",
        "!=", ";", "(", ")", "^", ",", "\"", "\'", "#", "&",
        "&&", "|", "||", "%", "~", "<<", ">>", "[", "]", "{",
        "}", "\\", ".", "\?", ":", "!"
};

static char IDENTIFIER_TABLE[1000][50] = {""};//标识符表
/**
 * 判断当前字符是否是数字
 * */
bool DIGIT(char ch);

/**
 * 判断当前字符是否是字母 a-z|A-Z
 * 下划线开头也算在内
 * */
bool LETTER(char ch);

/**
 * 在保留字表RESERVE_TABLE[][]中查找TOKEN
 * */
int RESERVE(char *s);


/**
 * syn:种别码
 * code: 预处理过的代码
 * token: 关键字
 * */
int scanner(string code, int &pos);

/**
 * 输出文件
 **/
int word_anlysis(const string &code, const char *file_name);

#endif //COMPILEEX_EX2_FH