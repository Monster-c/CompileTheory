//
// Created by cw on 2021/4/20.
//

//
// Created by cw on 2021/4/19.
//

#include <stdio.h>
#include <malloc.h>
#include <string.h>

# define MAX 5

// 存储边
struct Arrow {
//    状态
    int nEndStateID;
//    箭头上的字符
    char chLetter;
//    与当前边有相同开始结点的下条边
    struct Arrow *pNextArrow;
};

// 存储结点（NFA的状态）
struct State {
//    顶点编号
    int nStateID;
//    当前顶点的连接的第一条箭弧的指针
    struct Arrow *pFirstArrow;
};

// NFA的所有状态
struct NFA {
//    头结点的数组
    struct State StateList[MAX];
//    有效状态的个数
    int stateCount;
//    箭弧的个数
    int arrowCount;
};

//状态栈
struct stateStack {
    //栈空间
    struct State *pStateList[MAX];
//    栈顶元素在数组中的下标
    int top;
};

//符号栈
struct operatorStack {
//    栈空间
    char chOperatorList[MAX];
//    栈顶
    int top;
};

/*
 * 随便写一个正则式
 * ((ab)|c)*
 *
 * */
//
//// main函数
//int getNFA() {
//
////    初始化状态栈
//    struct stateStack stateStack = {(struct State *) "", 0};
////    初始化符号栈
//    struct operatorStack operatorStack = {"", 0};
////    输入表达式
//    char *regex = (char *) malloc(MAX * 2);
//    scanf("%s", regex);
////    末尾添加#号
//    strcat(regex, "#");
////    符号入栈
//    strcpy(operatorStack.chOperatorList, regex);
//    operatorStack.top += sizeof(regex);
//
////    产生一个初始0号结点
//    stateStack.pStateList[stateStack.top++] = 0;
//
////
//    char ch = operatorStack.chOperatorList[operatorStack.top--];
//    while (1) {
////        符号出栈
////        char ch = operatorStack.chOperatorList[operatorStack.top--];
//
//        if (ch) {
////            如果当前字符是正则表达式的字符，则产生一对新的开始结束结点
//            struct State *newState;
//            struct Arrow *arrow;
//            newState = {0, arrow};
//            stateStack.pStateList[stateStack.top++] = newState;
////            将开始结点和结束结点压入状态栈
//        } else {
//            if()
//        }
//
//        break;
//    }
//
//
////    printf("%s",regex);
//    free(regex);
//
//    return 0;
//}