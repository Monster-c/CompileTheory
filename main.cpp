#include "./include/PreProcess.h"
#include "./include/Reg2NFA.h"
#include "./include/utils.h"
#include "./include/person_wolf_sheep_vegetable.h"
#include "./include/natural_cut_word.h"

int main() {
    // 文件预处理
    pre_process("../input.txt", "output1.txt");

//人狼羊菜
//SolveProblem();
//        Reg2NFA();
//        cout<< ""<<endl;
//        Reg2NFA();

    string proc_code = read_file("../input.txt");
//    cout << "proc_code:" << proc_code << endl;

    string pre_code = filter(proc_code);
//    cout << "输出预处理过的程序" << pre_code << endl;

    word_anlysis(pre_code, "Ex2.txt");
    return 0;
}