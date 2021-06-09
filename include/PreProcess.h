//
// Created by cw on 2021/5/28.
//

#ifndef COMPILEEX_ALLFUNC_FH
#define COMPILEEX_ALLFUNC_FH

#include "utils.h"

/**
 * 读取源程序文件
 * @ret: 读取的结果字符串
 * */
string read_file(const string &input_file);

/**
 * 主方法
 * */
int pre_process(const string &input_filename, const string &output_filename);

/**
 * 预处理过滤
 * @param {data}:源程序代码
 * @ret {string}:预处理过的结果字符串
 * */
string filter(string data);

/**
 * 将预处理程序写入文件
 * */
int write_file(const string &content, const string &kOutPutFile);

#endif //COMPILEEX_ALLFUNC_FH