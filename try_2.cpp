// learn getline

#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v{7, 5, 9, 3};  // 显然这个尖括号里指示的是向量的数据类型
    v.push_back(7);  // 这个push_back的作用是在后面添加数据

    //遍历向量的方法如下所示
    for(int n : v) {
        cout << n << '\n';  // 从这个示例的输出可以看出 一个 << 操作完之后 后面一个 << 顶上来，接着上一个操作完的残羹剩饭继续操作
    }

    array<int, 3> a1{ {1, 2, 3} };  // array 是一个数组，需要指定长度和数据类型
    array<int, 3> a2 = {1, 2, 4};  // this is another way to build array

    array<string, 2> a3 = { "2", "r" };

    sort(a1.begin(), a1.end());  // 这个begin 的作用是从开头开始返回一个迭代器 end也一样
    reverse_copy(a2.begin(), a2.end(),  // 这个reverse_copy的功能正如其名字 然后它的最后一个参数是要输出的地方
            ostream_iterator<int>(cout, " "));  // 这个ostream的作用是接受别人丢过来的指定数据
                                               // 然后输入到指定的对象中，最后一个是指定的分隔符
    cout << '\n';
    for(const auto& s: a3)
        cout << s << ' ';
    /*
     * 这个auto是一个蛮神奇的东西
     *
     * 如果单走一个auto 就是拷贝一份，不会对原数据造成影响
     * 如果auto带个& 就是一个引用，这就意味着可以修改原数据
     *
     * 但是这里 const auto& 就可以避免拷贝的开销，只读取数据
     *
     * */

     vector<array<char, 4>> vec;  // 这个似乎是比较进阶的做法了，这个意味着这个向量的元素是一个数组，这个数组可以装下四个字符串

    istringstream input("abc|def|gh");  // 这个istringstream似乎是用于构建一个流的

    for(array<char, 4> a; input.getline(&a[0], 4, '|'); ) {
        vec.push_back(a);
        /* 这里初始化了一个数组对象
         * 这里真的很有趣
         *
         * 首先初始化一个数组对象，然后中间这个因素是循环继续的条件，最后一个留空意味着每一次并不做什么
         *
         * 从这个input里getline， 究竟怎么getline呢？
         *
         * 第一个参数是指针，要开始写入的指针，给出开始的位置就OK了
         * 第二个参数指出了由第一个指针所指出的规模
         * 第三个参数指出了每一行所需的分隔符
         * */
    }

    for(auto& a : vec) {
        cout << &a[0] << '\n';
    }
}