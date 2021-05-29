//
// Created by cw on 2021/5/28.
//

//#include "AllFunc.h"
#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int preProcess() {
    //    读取的数据/最终结果
    string data, result;
    // 匹配注释
    regex reg("//.*");

    // 以读模式打开文件
    ifstream infile;
    infile.open("Expression.txt", ios::in);

    while (infile >> data) {
        // 对字符串进行匹配
        if (data == "\t" || data == "\n") {
            continue;
        } else if (regex_match(data, reg)) {
            cout << data << endl;
            data = "";
            continue;
        } else {
            cout << "output:" << data << endl;
            result += data;
        }
    }
    infile.close();

    cout << result;

    //保存结果
    ofstream outfile;
    outfile.open("./output.txt", ios::out | ios::trunc);
    outfile << result << endl;

    return 0;
}

