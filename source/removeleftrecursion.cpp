//
// Created by cw on 2021/6/7.
//

#include"../include/utils.h"
#include "../include/RemoveLeftRecursion.h"

/**
 * 代码实现
 * */
int RemoveLeftRecursion() {
    int i, n;
    freopen("xczdg.in", "r", stdin);
    printf("Plese input P count :");
    scanf("%d", &n);
    printf("\n");
    G g;
    g.pcount = n;
    //g.p = (P *)malloc(sizeof(P)*n);
    for (i = 0; i < n; i++) {
        scanf("%d%*c", &g.p[i].count);
        g.p[i].key = getchar();
        getchar();
        char ch, str[255];
        int sp = 0, c = 0;
        while ((ch = getchar()) != '\n') {
            if ('|' == ch) {
                str[sp] = '\0';
                g.p[i].value[c] = (char *) malloc(sizeof(char) * 255);
                strcpy(g.p[i].value[c], str);
                sp = 0;
                c++;
            } else {
                str[sp] = ch;
                sp++;
            }
        }
        str[sp] = '\0';
        g.p[i].value[c] = (char *) malloc(sizeof(char) * 255);
        strcpy(g.p[i].value[c], str);

        printf("%c=>%s|%s\n", g.p[i].key, g.p[i].value[0], g.p[i].value[1]);
    }

    for (i = 0; i < n; i++) {
        int j = 0;
        for (; j < i; j++) {
            // 将间接左递归转换成直接左递归
            // 扫描Ai的开始符号，一定要是非终结符
            int k;
            for (k = 0; k < g.p[i].count; k++) {
                char i_start = g.p[i].value[k][0];
                //printf("%c\n",start);
                if (i_start == g.p[j].key) {
                    // 满足 Ai->Ajr
                    char tmp[255];
                    char fiel[255];
                    strcpy(fiel, &g.p[i].value[k][1]);

                    strcpy(tmp, g.p[j].value[0]);
                    strcpy(g.p[i].value[k], strcat(tmp, fiel));
                    printf("%d %s\n", k, g.p[i].value[k]);
                    int m;
                    for (m = 1; m < g.p[j].count; m++) {
                        strcpy(tmp, g.p[j].value[m]);
                        g.p[i].value[g.p[i].count] = (char *) malloc(sizeof(char) * 255);
                        strcpy(g.p[i].value[g.p[i].count], strcat(tmp, fiel));
                        printf("%d %s\n", g.p[i].count, g.p[i].value[g.p[i].count]);
                        g.p[i].count++;

                    }
                }

            }
        }
        // 消除直接左递归
        // 扫描Pi.key 为产生式右部的所有产生式
        for (j = 0; j < g.p[i].count; j++) {
            char *pivj = g.p[i].value[j];
            if (g.p[i].key == pivj[0]) {
                // 存在直接左递归
                int m;
                for (m = 0; m < g.p[i].count; m++) {
                    if (m != j) {
                        // A->ρ1A'|ρ2A'|ρ3A'    ρρσσαα
                        char aci[2] = {g.p[i].key - 32, '\0'};
                        strcat(g.p[i].value[m], aci);         // 这里A'直接已A的ASCII码值减32表示
                    } else {
                        // A'->α1A'|α2A'|....|ε
                        g.p[g.pcount].key = g.p[i].key - 32;
                        g.p[g.pcount].value[0] = (char *) malloc(sizeof(char) * 255);
                        strcpy(g.p[g.pcount].value[0], &pivj[1]);
                        char aci[2] = {g.p[g.pcount].key, '\0'};
                        strcat(g.p[g.pcount].value[0], aci);
                        g.p[g.pcount].value[1] = (char *) malloc(sizeof(char) * 255);
                        strcpy(g.p[g.pcount].value[1], "kong");
                        g.p[g.pcount].count = 2;
                        g.p[i].value[j] = NULL;
                        g.pcount++;
                    }
                }
                break;
            }
        }

    }

    printf("\n-----------------------\n");
    // 打印文法
    for (i = 0; i < g.pcount; i++) {
        if (g.p[i].key) {
            if (g.p[i].key) printf("%c=>", g.p[i].key);
            int j;
            for (j = 0; j < g.p[i].count; j++) {
                if (g.p[i].value[j]) printf("%s ", g.p[i].value[j]);
            }
            printf("\n");
        }
    }
    free(g.p);
    return 0;
}