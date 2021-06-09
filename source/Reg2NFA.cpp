//
// Created by cw on 2021/5/28.
//

#include "../include/utils.h"
#include "../include/Reg2NFA.h"

const int MAX = 100;

/**
 * @brief:NFA使用图的邻接链表存储，邻接链表中存储边信息的结构体
 **/
struct Arrow {
    int nEndStateId;    //边终点id
    char chLetter;        //边上的字符
    struct Arrow *pNextArrow;    //与当前边起点相同的下一条边
};

/**
 * @brief:图的邻接链表中存储图的结点（NFA状态）信息的结构体
 **/
struct State {
    int nStateId;    //节点编号
    Arrow *pFirstArrow;    //当前点的出边链表的头指针
};
/**
 * @brief:NFA中的状态在图中用图的结点表示
 * NFA的所有状态保存在邻接链表的结点结构体数组中
 **/
struct NFA {
    State *StateList[MAX];    //邻接链表的头节点数组(就是NFA的状态)
    int stateCount;        //有效节点数量
    int arrowCount;        //边的个数
} NFA;

/**
 * @brief:每个输入符号都生成一个NFA（就是一堆开始节点和中间连着的边）
 * 输入符号生成NFA要进栈
 * 输入符号对应的NFA的栈的结构体
 **/
struct StateStack {
    State *state_list[MAX];    //栈空间
    int top;    //栈顶指针

    /**
     * 入栈操作
     **/
    void push(State *state) {
        state_list[++top] = state;
    }

    /**
     * 出栈操作
     **/
    State *pop() {
        return state_list[top--];
    }
} StateStack;

/**
 * @brief:正则表达式的符号栈
 **/
struct OperatorStack {
    char ch_operator_list[MAX];   //栈空间
    int top;    //栈顶指针

    void push(char ch) {
        ch_operator_list[++top] = ch;
    }

    char pop() {
        return ch_operator_list[top--];
    }

    char get_top() {
        return ch_operator_list[top];
    }
} OperatorStack;

/**
 * @brief:这里采用优先级 * > . > | > ( = )
 * @ret:算符优先级
 **/
int get_pri(char ch) {
    if (ch == '*') return 40;
    else if (ch == '.') return 30;
    else if (ch == '|') return 20;
    else if (ch == '(' || ch == ')') return 10;
    return 10;
}

//State get_state()
//{
//	State s;
//	NFA.stateCount ++ ;
//	s.nStateId = NFA.stateCount;
//	s.pFirstArrow = NULL;
//	NFA.StateList[NFA.stateCount] = s;
//	return s;
//}

/**
 * @brief:获取当前NFA状态
 * @ret: 状态
 * */
State *get_state() {
    auto *s = new State;
    NFA.stateCount++;
    int n = NFA.stateCount;
    s->nStateId = n;
    s->pFirstArrow = nullptr;
    NFA.StateList[n] = s;
    return s;
}

/**
 * @brief: 从a到b连接一条边，权重为ch
 **/
void add_edge(State *a, State *b, char ch) {
    auto *arrow = new Arrow;
    arrow->chLetter = ch;
    arrow->nEndStateId = b->nStateId;
    arrow->pNextArrow = nullptr;
    NFA.arrowCount++;
    if (a->pFirstArrow) {
        arrow->pNextArrow = a->pFirstArrow->pNextArrow;
        a->pFirstArrow->pNextArrow = arrow;
    } else
        a->pFirstArrow = arrow;
}

int Reg2NFA() {
    string reg;
    cin >> reg;
    /**
     * 相当于添加为  #reg#
     * */
    reg += '#';
    OperatorStack.push('#');
    // 遍历正则式
    for (int i = 0; i < reg.size();) {
        int ch = reg[i];
        /**
         * 当前字符是数字or字母
         * 则产生一对新开始和结束节点；
         * 在开始节点和结束节点之间拉一条标注为当前字符的边；
         * 将开始节点和结束节点压入状态栈；
         * 先压入开始结点，再压入结束节点
         * 读取下一个字符
         * */
        if (isalnum(ch)) {
            State *start = get_state();
            State *end = get_state();
            add_edge(start, end, ch);
            StateStack.push(start);
            StateStack.push(end);
            i++;    // 读取下一个字符
        } else
            /**不是字母或者数字----》是运算符，
             * 和符号栈栈顶元素比较，
             * 高于栈顶则入栈，
             * 低于栈顶就把符号栈栈顶元素出栈，
             * 再做运算
             */
        {
            //高于栈顶运算符优先级，入栈
            if (get_pri(ch) > get_pri(OperatorStack.get_top())) {
                OperatorStack.push(ch);
                i++;
            } else
                //如果低于栈顶运算符优先级，则弹出栈顶运算符并进行运算
            if (get_pri(ch) < get_pri(OperatorStack.get_top())) {
                char op = OperatorStack.pop();
                if (op == '.') {
                    //入栈的时候，是起点先入栈，终点后入栈，所以出栈的时候，终点先出栈
                    //先出栈的是连接运算后面的元素
                    State *ed2 = StateStack.pop();
                    State *st2 = StateStack.pop();
                    State *ed1 = StateStack.pop();
                    State *st1 = StateStack.pop();
                    //将2连在1的后面
                    State *st = get_state();
                    State *ed = get_state();
                    add_edge(st, st1, '?');
                    add_edge(ed1, st2, '?');
                    add_edge(ed2, ed, '?');
                    StateStack.push(st);
                    StateStack.push(ed);
                } else if (op == '*') {
                    //闭包运算符是一元运算符，只需要弹出一组点即可
                    State *ted = StateStack.pop();
                    State *tst = StateStack.pop();
                    State *st = get_state();
                    State *ed = get_state();
                    add_edge(st, tst, '?');
                    add_edge(ted, tst, '?');
                    add_edge(ted, ed, '?');
                    add_edge(st, ed, '?');
                    StateStack.push(st);
                    StateStack.push(ed);
                } else if (op == '|') {
                    State *ed1 = StateStack.pop();
                    State *st1 = StateStack.pop();
                    State *ed2 = StateStack.pop();
                    State *st2 = StateStack.pop();
                    State *st = get_state();
                    State *ed = get_state();
                    add_edge(st, st1, '?');
                    add_edge(st, st2, '?');
                    add_edge(ed1, ed, '?');
                    add_edge(ed2, ed, '?');
                    StateStack.push(st);
                    StateStack.push(ed);
                }
            } else    //运算符优先级相同
            {
                if (ch == ')' && OperatorStack.get_top() == '(') {
                    OperatorStack.pop();
                    continue;
                } else i++;
            }
        }
    }
    State *ed = StateStack.pop();
    State *st = StateStack.pop();
    for (int i = 1; i <= NFA.stateCount; i++) {
        Arrow *iter = NFA.StateList[i]->pFirstArrow;
        cout << i << "-";
        while (iter) {
            cout << iter->chLetter << "->" << iter->nEndStateId;
            iter = iter->pNextArrow;
        }
        cout << endl;
    }
    return 0;
}