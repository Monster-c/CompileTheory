//
// Created by cw on 2021/5/28.
//

#pragma once
#ifndef COMPILEEX_EX2_FH
#define COMPILEEX_EX2_FH

#include<fstream>
#include <string>
#include <iostream>

// 定义数组最大长度
#define MAX_LENGTH 999
// 计算数组长度
#define lengthof(m) sizeof(m)/sizeof(m[0])

class Ex2 {
private:
    std::ifstream infile;
    char buffer[MAX_LENGTH];// 字符数组，存放源代码文本
    char CHAR; // 字符变量，存放最新读进的源程序字符
    char TOKEN[MAX_LENGTH]; // 字符数组，存放单词的字符串

    int searchIndex; //buffer索引
    int position; //token当前位置

public:
    Ex2(const char *filename) {
        infile.open(filename, std::ios::in);// 读取经过预处理的代码文件
        infile >> buffer;
//        position = 0;   //buffer指示器
        searchIndex = 0;
    }

    int prints() {
        std::cout << "Test Output:" << buffer << std::endl;
        return 0;
    }


    /**
     * 将下一输入字符读入CHAR，搜索指示器searchIndex前移一个字符
     * */
    char GETCHAR(char buff[], int &Index);

    /**
     * 检查CHAR中的字符是否为空白。若是则调用GETCHAR直至CHAR中进入一个非空白字符
     * */
    char GETBC(char buffer[], int &Index);

    /**
     * 把CHAR中的字符连接到TOKEN之后。
     * */
    void CONCAT(char TOKEN[], char CHAR);

    /**
     * 判断CHAR中的字符是不是字母，从而给出真假值TRUE、FALSE
     * */
    bool LETTER(char ch);

    /**
     * 判断CHAR中的字符是不是数字，从而给出真假值TRUE、FALSE
     * */
    bool DIGIT(char ch);

    /**
     * 在保留字表RESERVE_TABLE[][]中查找TOKEN
     * */
//    void RESERVE(char RESERVE_TABLE[][MAX_LENGTH], char TOKEN[]);

    /**
     * 把搜索指示器回调一个字节，把CHAR中的字符置为空白
     * */
//    void RETRACT(char buffer[], int *searchIndex);

    ~Ex2() {
        infile.close();
    }
};

#endif //COMPILEEX_EX2_FH
