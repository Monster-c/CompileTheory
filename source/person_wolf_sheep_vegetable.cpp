//
// Created by cw on 2021/6/5.
//

#include "../include/utils.h"
#include "../include/person_wolf_sheep_vegetable.h"

int N;      //顶点数
int G[MAXV][MAXV];      //邻接矩阵

int pre[MAXV];
bool vis[MAXV];
int d[MAXV];    //步骤数

/**
 * @brief:假设状态01代表河的两岸
 * 0：当前位置
 * 1：对岸
 * */

int GetBit(int num, int n) {
    return (num >> n) & 1;
}

void SetBit(int &num, int n, int b) {
    if (GetBit(num, n) && b) {
        return;
    } else if (GetBit(num, n) == 0 && b == 0) {
        return;
    } else if (GetBit(num, n) == 1 && b == 0) {
        int mask = (~(1 << n));
        num = num & mask;
    } else {
        int mask = 1 << n;
        num = num | mask;
    }
}

bool StateIsOk(int u, int v) {
    return ((fabs(u ^ v) == 0) || (fabs(u ^ v) == 1) || (fabs(u ^ v) == 2) || fabs(u ^ v) == 4);
}

bool check(int u, int b) {
    int x = ((u >> 2) & 1), y = ((u >> 1) & 1), z = u & 1;
    if (x == y && x == b) return false;
    if (y == z && y == b) return false;
    return true;
}

void mkgraph() {
    N = 16;       //顶点数为16，每个顶点对应的二进制编号为(人狼羊菜)，表示河一边是否存在相应的东西，存在为1
    fill(G[0], G[0] + MAXV * MAXV, INF);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {             //i状态 -> j状态
            if (i == j) continue;        //不存在自循环边

            if ((((i >> 3) & 1) ^ ((j >> 3) & 1)) == 0) continue;        //人不运输状态转换不可以

            int u = i, v = j;
            if (u > v) u = u - 8; else v = v - 8;

            if (GetBit(i, 3) == 1) {       //最高位为1
                if (u < v) continue;
                if (StateIsOk(u, v) && check(v, 1)) {
                    G[i][j] = 1;
                    continue;
                }
            } else if (GetBit(i, 3) == 0) {
                if (u > v) continue;
                if (StateIsOk(u, v) && check(v, 0)) {
                    G[i][j] = 1;
                    continue;
                }
            }
        }
    }
}


//从 1111 -> 0000
bool Dijkstra(int s) {
    fill(d, d + MAXV, INF);
    fill(pre, pre + MAXV, -1);
    d[s] = 0;
    for (int i = 0; i < N; i++) {
        int u = -1, MIN = INF;
        for (int j = 0; j < N; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return false;
        vis[u] = true;
        for (int v = 0; v < N; v++) {
            if (!vis[v] && G[u][v] != INF && d[v] > d[u] + G[u][v]) {
                d[v] = d[u] + G[u][v];
                pre[v] = u;
            }
        }
    }
    return true;
}

int SolveProblem() {
    mkgraph();
    Dijkstra(15);

    cout << "need " << d[0] << " step,the way is as follow:" << endl;
    stack<int> s;
    int x = 0;
    while (x != -1) {
        s.push(x);
        x = pre[x];
    }
    while (!s.empty()) {
        char res[999];
        itoa(s.top(), res, 2);

        printf("%s\t", res);
        cout << s.top() <<endl;
        s.pop();
    }
    cout << endl;

    return 0;
}