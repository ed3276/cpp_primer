#include <iostream>

using namespace std;

class Y;

class X{
    using pos = size_t;
public :
    pos h();
private :
    Y *py;

};

X::pos X::h() { return 1; }

class Y{
    X x;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
