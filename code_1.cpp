/*
 * 某涉密单位下发了某种票据，并要在年终全部收回。
每张票据有唯一的ID号。全年所有票据的ID号是连续的，但ID的开始数码是随机选定的。
因为工作人员疏忽，在录入ID号的时候发生了一处错误，造成了某个ID断号，另外一个ID重号。
你的任务是通过编程，找出断号的ID和重号的ID。
假设断号不可能发生在最大和最小号。
要求程序首先输入一个整数N(N<100)表示后面数据行数。
接着读入N行数据。
每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于100000）
每个整数代表一个ID号。

要求程序输出1行，含两个整数m n，用空格分隔。
其中，m表示断号ID，n表示重号ID
例如：
用户输入：
2
5 6 8 11 9
10 12 9
则程序输出：
7 9
 *
 * */

#include <iostream>
// #include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void s2i(string &str, int &num) {
    stringstream ss;
    ss << str;
    ss >> num;  // 可能是提取输入的数字吧 注意这里用的是引用 所以会直接改变这个地址内的数值
}

int line;
const int MaxN = 10000;
int data[MaxN];  // 数据数组

int main() {
    scanf("%d", &line);  // 获取输入的数字，这里是行数
    getchar();  // 可以把换行符给吃掉
    int index = 0;
    for(int i = 0; i < line; i++) {
        string s;
        getline(cin, s);  // cin是从标准输入读取数据，相当于具体的数字id
        istringstream iss(s);  // 似乎是个强制类型转换,就是类型转换
        string tmp;
        while(getline(iss, tmp, ' ')) {  // getline(源，目标，分隔符)
            s2i(tmp, data[index++]);  // 把数据提取到data中，非常聪明的办法
        }
        sort(data, data+index);  // 这个last就是需要排序的最后一个数 需要algorithm
    }
    int a, b;
    for(int i = 1; i < index; i++) {
        if(data[i] == data[i - 1] + 2)
            a = data[i] - 1;  // 断号
        if(data[i] == data[i - 1])
            b = data[i];  // 重号
    }
    printf("%d %d", a, b);
    return 0;
}

