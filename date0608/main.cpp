#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "common.h"
#include <memory>
using namespace std;

template bool compare(const int&, const int&);

class NoDefault
{
    NoDefault(int) { }
};

//template class vector<NoDefault>;//实例化定义

template <typename T> class Stack {
public:
    Stack();
};
template <typename T> Stack<T>::Stack() { }
template Stack<char>::Stack();

//void f1(Stack<char> c){ c; }
class Exercise {
    Stack<double> &rsd;
    Stack<int> si;
};

template <typename Tp> class sharing_ptr
{
    template <typename Rp>
    struct sharing_del
    {
        sharing_del(Rp *r) : rp(r) { }
        Rp *rp;
    };
public:
    template <typename Rp>
    sharing_ptr(Rp *rp) : ptr(rp), use_count(new int(1)) { }
    template <typename Rp, typename Deleter>
    sharing_ptr(Rp *rp)
private:
    Tp * ptr;
    int * use_count;
    shared_del
};

int main()
{
    cout << "Hello world!" << endl;
    cout << compare(8, 5) << endl;
    //Stack<char> *sc;
    //f1(*sc);
    //int iObj = sizeof(Stack<string>);
    {
        shared_ptr<int> sp;
    }
    return 0;
}


//使用下面注释的代码来生成c[1..99].cpp文件，里面包含一个要实例化的模板
/*
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    cout << "Hello world!" << endl;
    //cout << compare(8, 5) << endl;
    string s("c");
    const int N = 100;
    char buffer[sizeof(int)+1];
    ifstream infile("c1.cpp");
    string code, tmp, target("main1");
    while (getline(infile, tmp)) {
        code += tmp +'\n';
    }
    for (int i = 2; i != N; ++i) {
        string no(itoa(i, buffer, 10));
        string file = s + no + ".cpp";
        string codecpy(code), rep("main");
        codecpy.replace(codecpy.find(target), target.length(), rep + no);
        ofstream osfile(file);
        osfile << codecpy;
    }

    return 0;
}
*/
