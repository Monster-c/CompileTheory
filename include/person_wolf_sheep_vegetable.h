//
// Created by cw on 2021/6/5.
//

/**
 * 实验四：人狼羊菜过河问题
 * */

#ifndef COMPILEEX_PERSON_WOLF_SHEEP_VEGETABLE_H
#define COMPILEEX_PERSON_WOLF_SHEEP_VEGETABLE_H


#define MAXV 100
#define INF 0x7ffff

/**
 * 假设状态最初为（人，狼，羊，菜）
 * 状态从1111 ——> 0000 即表示过河成功
 * */


int GetBit(int num, int n);

void SetBit(int &num, int n, int b);

bool StateIsOk(int u, int v);

bool check(int u, int b);

void mkgraph();

// 使用Dijkstra算法解决
bool Dijkstra(int s);

int SolveProblem();

#endif //COMPILEEX_PERSON_WOLF_SHEEP_VEGETABLE_H
