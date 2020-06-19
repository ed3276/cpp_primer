#include <iostream>

using namespace std;
double PII = 3.14;
int main()
{
    cout << "Hello world!" << endl;
    char ch = -1;
    std::cout << ch << std::endl;
    const int *pi;
    constexpr double PI = 3.141592654;
    constexpr double &rPI = PII;
    constexpr double *pPI = &PII;
    using integer = int;
    integer i1 = 1;
    integer *pi1 = &i1;
    *pi1 = 5;
    std::cout << i1 << std::endl;
    return 0;
}
