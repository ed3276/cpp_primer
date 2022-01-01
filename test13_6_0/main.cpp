#include <iostream>
#include <utility>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int i = 42;
    int &r = i;
    int &&rr = std::move(i);

    int &r2 = i * 42;
    const int &r3 = i * 42;
    int &&rr2 = i*42;
    return 0;
}
