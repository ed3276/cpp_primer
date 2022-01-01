#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    {
        int i = 42;
        int &r = i;
        //int &&rr = i;
        //int &r2 = i * 42;
        const int &r3 = i * 42;
        int &&rr2 = i * 42;
        int &&rr3 = 42;
        //int &&rr4 = rr3;
    }
    {
        string s1 = "a value", s2 = "another";
        auto n = (s1 + s2).find('a');
        s1 + s2 = "wow";
    }
    return 0;
}
