//
// Created by cw on 2021/5/28.
//

#include "../include/PreProcess.h"

string read_file(const string &input_file) {
    ifstream infile;
    char data[999];   //保存读取内容
    int i = 0;

    infile.open(input_file, ios::in);
    while (!infile.eof()) {
        infile.get(data[i++]);
    }
    infile.close();

    data[i - 1] = '\0';
    return data;
}

int pre_process(const string &kInputFile, const string &kOutputFile) {

    string result; //保存结果

    string data = read_file(kInputFile);
    cout << "源程序为:\n" << data << endl;

    result = filter(data);
    cout << "处理过后：" << result << endl;

    write_file(result, kOutputFile);

    return 0;
}

// 过滤多余字符
string filter(string data) {
    string res;
    for (int i = 0; i < data.length(); i++) {
        // 匹配单行注释
        if (data[i] == '/' && data[i + 1] == '/') {
            while (data[i] != '\n') i++;
        }
        // 匹配多行注释
        if (data[i] == '/' && data[i + 1] == '*') {
            i += 2;
            while (data[i] != '*' && data[i + 1] != '/') {
                if (data[i] == '\0') {
                    cout << "error! 多行注释匹配出错！" << endl;
                    exit(0);
                }
                i++;
            }
            i += 2;
        }
        if (data[i] != ' ' && data[i] != '\n' && data[i] != '\t' && data[i] != '\v' && data[i] != '\r' &&
            data[i] != '\0') {
            res += data[i];
        }
    }

    return res;
}

int write_file(const string &content, const string &kOutPutFile) {
    ofstream out;
    out.open(kOutPutFile, ios::trunc | ios::out);
    out << content << endl;
    out.close();
}