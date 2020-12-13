#include <iostream>
#include <cstdlib>

const int& addi(int &i1, const int i2)
{
    i1 = i1+i2;
    return i1;
}

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    int a1 = 1;
    int a2 = 2;
    int a3 = a1 bitor a2;
    std::cout << a3 << std::endl;
    int &ra1 = a1;
    ra1 = ra1;
    ra1 = addi(ra1, a2);



    //addi(ra1, a2) = 10;
    std::cout << ra1 << std::endl;

    int *pa1 = &ra1;
    std::cout << *pa1 << std::endl;
    int *p2 = NULL;
    return 0;
}
