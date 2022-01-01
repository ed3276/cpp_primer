#include <iostream>
#include "common.h"
using namespace std;

template bool compare(const int&, const int&);

//template bool compare(const int&, const int&);

template <typename T> class Stack {
public:
    Stack();
};
extern template class Stack<char>;
//extern template Stack<char>::Stack();
int main1()
{
    cout << "Hello world!" << endl;
    cout << compare(8, 5) << endl;
    Stack<char> sc;
    sc = sc;
    return 0;
}
