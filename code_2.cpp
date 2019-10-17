//小明正在玩一个“翻硬币”的游戏。
//桌上放着排成一排的若干硬币。我们用 * 表示正面，用 o 表示反面（是小写字母，不是零）。
//比如，可能情形是：**oo***oooo
//如果同时翻转左边的两个硬币，则变为：oooo***oooo
//现在小明的问题是：如果已知了初始状态和要达到的目标状态，每次只能同时翻转相邻的两个硬币,那么对特定的局面，最少要翻动多少次呢？
//我们约定：把翻动相邻的两个硬币叫做一步操作，那么要求：
//程序输入：
//两行等长的字符串，分别表示初始状态和要达到的目标状态。每行的长度<1000
//程序输出：
//一个整数，表示最小操作步数
//例如：
//用户输入：
//**********
//o****o****
//程序应该输出：
//5
//再例如：
//用户输入：
//*o**o***o***
//*o***o**o***
//程序应该输出：
//1

#include <bits/stdc++.h>

using namespace std;

int main() {
    string src;
    string target;
    getline(cin, src);  // 这个getline的方法 很有意思 可以说是获取用户信息的标准方法
    getline(cin, target);
    int n = src.length();
    int ans = 0;
    int start = -1;

    for(int i = 0; i < n; i++) {
        if(src[i] != target[i]) {
            if (start == -1) {
                start = i;
            } else {
                ans = (i - start);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
