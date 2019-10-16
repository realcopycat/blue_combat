#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main()
{
    string input = "3.1185 8888 4.22 55 true mellomello";
    istringstream streams12(input);  // 显然这个 streams12 这个名字是任意的
    char c;
    const int MAX = 7;
    char cstr[MAX];

    streams12 >> setw(MAX) >> cstr >> c;  // setw设置了输出的长度 显然一旦有空格就会阻断这个 >> 运算符的数据提取
    cout << "c = " << c << '\n'
         << "cstr = " << cstr << '\n';

    return 0;
}

/*
 * output:
 * c= 8
 * cstr = 3.1185  // 这里总是会少一位是因为c++总是要为字符串数组添加一个 /0 作为结尾的标记
*/
