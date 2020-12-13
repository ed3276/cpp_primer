#include <iostream>

using namespace std;

extern const double pi = 3.14;
void prog1();
constexpr double PI(){    return 3.1415926;}
int main()
{
    cout << "Hello world!" << endl;
    int i1 = -1, i2 = 1;
    unsigned i3 = 1;
    std::cout << i1*i2 << std::endl;
    std::cout << i1*i3 << std::endl;


    std::cout << "\1234"  << '\n';

    int a = 10;
    int *pa = &a;
    int &ra = *pa;
    std::cout << ra << std::endl;


    int *&rpa = pa;
    *rpa = 30;
    std::cout << *rpa << std::endl;

    int b20 = 20;
    const int cb1 = b20;
    int b21 = cb1;
    std::cout << b21 << std::endl;

    std::cout << "in " << __FILE__ << " , " << __FUNCTION__ << " at line: " << __LINE__ << std::endl;
    std::cout << pi << std::endl;

    prog1();


    //const int *constip = &(42);
    constexpr double cPI = PI();
    (void)cPI;
    std::cout << PI() << std::endl;

    int r45 = 0, &rr45 = r45;
    decltype((rr45)) r47;
    return 0;
    }
