//
// Created by cw on 2021/5/28.
//

#include "../include/Ex2.h"
#include<regex>
//#include <iostream>

// 构造词法分析器-自然分词
//int cutWord() {
//    return 0;
//}

/**
* 将下一输入字符读入CHAR，搜索指示器searchIndex前移一个字符
**/
char Ex2::GETCHAR(char buff[], int &Index) {
    if (Index < lengthof(buff))
        return buff[Index++];
    else {
        std::cout << "error,out of range!!";
        return ' ';
    }
}

/**
* 检查CHAR中的字符是否为空白。若是则调用GETCHAR直至CHAR中进入一个非空白字符
**/
char Ex2::GETBC(char buff[], int &Index) {
    char ch = GETCHAR(buff, Index);
    if (ch == ' ')
        ch = GETCHAR(buff, Index);
    return ch;
}

/**
*把CHAR中的字符连接到TOKEN之后。
**/
void Ex2::CONCAT(char token[], char nowCh) {
//    token[]
}


// 判断当前字符是否是数字
bool Ex2::DIGIT(char ch) {
    if (ch >= 48 && ch <= 57)
        return true;
    return false;
}

// 判断当前字符是否是字母 a-z|A-Z
// 下划线开头也算在内
bool Ex2::LETTER(char ch) {
    if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122) || ch == '_')
        return false;
    return true;
}


/**
 * 在保留字表RESERVE_TABLE[][]中查找TOKEN
 * */
    void RESERVE(char RESERVE_TABLE[][MAX_LENGTH], char TOKEN[]);

/**
 * 把搜索指示器回调一个字节，把CHAR中的字符置为空白
 * */
    void RETRACT(char buffer[], int *searchIndex);
