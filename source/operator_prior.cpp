//
// Created by cw on 2021/6/10.
//

#include "../include/operator_prior.h"

vector<char> VT;    // 终结符集合
vector<WF> VN_set;  //非终结符集合
map<string, int> VN_dic;

int used[MAX];
int vis[MAX];

// 存储算符优先表
char relation[MAX][MAX];
set<char> FIRSTVT[MAX];
set<char> LASTVT[MAX];

void dfs(int x) {
    if (vis[x]) return;
    vis[x] = 1;
    string &left = VN_set[x].left;
    for (int i = 0; i < VN_set[x].right.size(); i++) {
        string &str = VN_set[x].right[i];
        if (isupper(str[0])) {
            int y = VN_dic[str.substr(0, 1)] - 1;
            if (str.length() > 1 && !isupper(str[1]))
                FIRSTVT[x].insert(str[1]);
            dfs(y);
            auto it = FIRSTVT[y].begin();
            for (; it != FIRSTVT[y].end(); it++)
                FIRSTVT[x].insert(*it);
        } else
            FIRSTVT[x].insert(str[0]);
    }
}

void make_firstvt() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < VN_set.size(); i++)
        if (vis[i]) continue;
        else dfs(i);
#define DEBUG
#ifdef DEBUG
    puts("------------FIRSTVT集-------------------");
    for (int i = 0; i < VN_set.size(); i++) {
        printf("%s : ", VN_set[i].left.c_str());
        auto it = FIRSTVT[i].begin();
        for (; it != FIRSTVT[i].end(); it++)
            printf("%c ", *it);
        puts("");
    }
#endif
}

void dfs1(int x) {
    if (vis[x]) return;
    vis[x] = 1;
    string &left = VN_set[x].left;
    for (int i = 0; i < VN_set[x].right.size(); i++) {
        string &str = VN_set[x].right[i];
        int n = str.length() - 1;
        if (isupper(str[n])) {
            int y = VN_dic[str.substr(n, 1)] - 1;
            if (str.length() > 1 && !isupper(str[n - 1]))
                LASTVT[x].insert(str[1]);
            dfs1(y);
            auto it = LASTVT[y].begin();
            for (; it != LASTVT[y].end(); it++)
                LASTVT[x].insert(*it);
        } else
            LASTVT[x].insert(str[n]);
    }
}

void make_lastvt() {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < VN_set.size(); i++)
        if (vis[i]) continue;
        else dfs1(i);
#define DEBUG
#ifdef DEBUG
    puts("--------------LASTVT集---------------------");
    for (int i = 0; i < VN_set.size(); i++) {
        printf("%s : ", VN_set[i].left.c_str());
        auto it = LASTVT[i].begin();
        for (; it != LASTVT[i].end(); it++)
            printf("%c ", *it);
        puts("");
    }
#endif
}

void make_operator_prior_table() {
    for (auto &i : relation)
        for (char &j : i)
            j = ' ';
    for (auto &i : VN_set)
        for (auto &str : i.right) {
            for (int k = 0; k < str.length() - 1; k++) {
                if (!isupper(str[k]) && !isupper(str[k + 1]))
                    relation[str[k]][str[k + 1]] = '=';
                if (!isupper(str[k]) && isupper(str[k + 1])) {
                    int x = VN_dic[str.substr(k + 1, 1)] - 1;
                    auto it = FIRSTVT[x].begin();
                    for (; it != FIRSTVT[x].end(); it++)
                        relation[str[k]][*it] = '<';
                }
                if (isupper(str[k]) && !isupper(str[k + 1])) {
                    int x = VN_dic[str.substr(k, 1)] - 1;
                    auto it = LASTVT[x].begin();
                    for (; it != LASTVT[x].end(); it++)
                        relation[*it][str[k + 1]] = '>';
                }
                if (k > str.length() - 2) continue;
                if (!isupper(str[k]) && !isupper(str[k + 2]) && isupper(str[k + 1]))
                    relation[str[k]][str[k + 2]] = '=';
            }
        }
#define DEBUG
#ifdef DEBUG
    for (int i = 0; i < VT.size() * 5; i++)
        printf("-");
    printf("算符优先关系表");
    for (int i = 0; i < VT.size() * 5; i++)
        printf("-");
    puts("");
    printf("|%8s|", "");
    for (char i : VT)
        printf("%5c%5s", i, "|");
    puts("");
    for (int i = 0; i < (VT.size() + 1) * 10; i++)
        printf("-");
    puts("");
    for (int i = 0; i < VT.size(); i++) {
        printf("|%4c%5s", VT[i], "|");
        for (int j = 0; j < VT.size(); j++)
            printf("%5c%5s", relation[VT[i]][VT[j]], "|");
        puts("");
        for (int i = 0; i < (VT.size() + 1) * 10; i++)
            printf("-");
        puts("");
    }
#endif
}

void make_it() {
    int n;
    char s[MAX];
    while (~scanf("%d", &n)) {
        memset(used, 0, sizeof(used));
        for (int i = 0; i < n; i++) {
            scanf("%s", s);
            int len = strlen(s);
            int j=0;
            for (; j < len; j++)
                if (s[j] == '-')
                    break;
            s[j] = 0;
            if (!VN_dic[s]) {
                VN_set.push_back(WF(s));
                VN_dic[s] = VN_set.size();
            }
            int x = VN_dic[s] - 1;
            VN_set[x].insert(s + j + 2);
            for (int k = 0; k < j; k++)
                if (!isupper(s[k])) {
                    if (used[s[k]]) continue;
                    used[s[k]] = 1;
                    VT.push_back(s[k]);
                }
            for (int k = j + 2; k < len; k++)
                if (!isupper(s[k])) {
                    if (used[s[k]]) continue;
                    VT.push_back(s[k]);
                    used[s[k]] = VT.size();
                }
        }
#define DEBUG
#ifdef DEBUG
        puts("************VT集*******************");
        for (char i : VT)
            printf("%c ", i);
        puts("");
        puts("*************产生式*****************");
        for (auto &i : VN_set)
            i.print();
        puts("************************************");
#endif
        make_firstvt();
        make_lastvt();
        make_operator_prior_table();
    }
}

