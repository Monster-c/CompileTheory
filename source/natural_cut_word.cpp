//
// Created by cw on 2021/5/28.
//

#include "../include/natural_cut_word.h"

// 保存关键字
char token[20] = {0};

bool DIGIT(char ch) {
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}

bool LETTER(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch <= 'Z' && ch >= 'A') || ch == '_')
        return true;
    return false;
}

int RESERVE(char *s) {
    for (int i = 0; i < 32; ++i) {
        if (strcmp(RESERVE_TABLE[i], s) == 0)
            return i + 1;//返回种别码
    }
    return -1;
}

int scanner(string code, int &pos) {
    int syn = 0;
    int count = 0;
//    int pos = 0;    //位置索引
    char ch;
//    char token[1000];
    ch = code[pos];
    while (ch == ' ')//去掉空格
    {
        pos++;
        ch = code[pos];
    }
    for (char &i : token)//清空token
    {
        i = '\0';
    }
    if (LETTER(code[pos])) {//以字母开头
        token[count++] = code[pos++];
        //后面是字母或数字
        while (LETTER(code[pos]) || DIGIT(code[pos])) {
            token[count++] = code[pos++];
        }
        token[count] = '\0';
        syn = RESERVE(token);//查表找到种别码
        if (syn == -1) {//若不是保留字则是标识符
            syn = 100;//标识符种别码
        }
        return syn;
    } else if (DIGIT(code[pos])) {//以数字开头
        token[count++] = code[pos++];
        //后面是数字
        while (DIGIT(code[pos])) {
            token[count++] = code[pos++];
        }
        token[count] = '\0';
        syn = 99;
        return syn;
    } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ';' || ch == '(' || ch == ')' || ch == '^'
               || ch == ',' || ch == '\"' || ch == '\'' || ch == '~' || ch == '#' || ch == '%' || ch == '['
               || ch == ']' || ch == '{' || ch == '}' || ch == '\\' || ch == '.' || ch == '\?' || ch == ':') {
        token[count++] = code[pos++];
        token[count] = '\0';
        for (int i = 0; i < 36; ++i) {
            if (strcmp(OPERATOR_OR_DELIMITER[i], token) == 0) {
                syn = 33 + i;
                break;
            }
        }
        return syn;
    } else if (ch == '<') {//可能是< <= <<
        pos++;
        if (code[pos] == '=')//<=
        {
            syn = 38;
        }
        if (code[pos] == '<')//<<
        {
            syn = 58;
        } else//<
        {
            pos--;
            syn = 37;
        }
        pos++;
        return syn;
    } else if (ch == '>') {//可能是> >= >>
        pos++;
        if (code[pos] == '=')//>=
        {
            syn = 40;
        }
        if (code[pos] == '>')//>>
        {
            syn = 59;
        } else//>
        {
            pos--;
            syn = 39;
        }
        pos++;
        return syn;
    } else if (ch == '=') {//可能是= ==
        pos++;
        if (code[pos] == '=')//==
        {
            syn = 42;
        } else {//=
            pos--;
            syn = 41;
        }
        pos++;
        return syn;
    } else if (ch == '!') {//可能是! !=
        pos++;
        if (code[pos] == '=')//==
        {
            syn = 43;
        } else {
            pos--;
            syn = 68;
        }
        pos++;
        return syn;
    } else if (ch == '&') {//可能是& &&
        pos++;
        if (code[pos] == '&')//&&
        {
            syn = 53;
        } else {//&
            pos--;
            syn = 52;
        }
        pos++;
        return syn;
    } else if (ch == '|') {//可能是| ||
        pos++;
        if (code[pos] == '|')//||
        {
            syn = 55;
        } else {
            pos--;
            syn = 54;
        }
        ++pos;
        return syn;
    } else if (ch == '\0')//文件结束
    {
        syn = 0;
    } else {
        cout << "wrong letter:" << ch <<
             endl;
        exit(0);
    }
}

int word_anlysis(const string &code, const char *kOutFile) {
    ofstream out;
    out.open(kOutFile, ios::out | ios::trunc);
    int syn = -1;
    static int pos = 0;
    while (syn != 0)//开始扫描
    {
        syn = scanner(code, pos);
        cout << " 当前种别码：" << syn << endl;
        if (syn == 100)//标识符
        {
            for (auto &i : IDENTIFIER_TABLE) {//插入标识符表
                if (strcmp(i, token) == 0) {//已存在表中
                    break;
                } else if (strcmp(i, "") == 0) {
                    strcpy(i, token);
                    break;
                }
            }
            cout << "标识符:" << token << endl;
            out << "标识符:" << token << endl;
        } else if (syn == 99)//常数
        {
            cout << "常数:" << token << endl;
            out << "常数:" << token << endl;
        } else if (syn <= 32 && syn >= 1)//保留字
        {
            cout << RESERVE_TABLE[syn - 1] << ":" << syn << endl;
            out << RESERVE_TABLE[syn - 1] << ":" << syn << endl;
        } else if (syn >= 33 && syn <= 68)//运算符或界符
        {
            cout << OPERATOR_OR_DELIMITER[syn - 33] << ":" << syn << endl;
            out << OPERATOR_OR_DELIMITER[syn - 33] << ":" << syn << endl;
        }
//        getchar();
    }
    out.close();
    return 0;
}