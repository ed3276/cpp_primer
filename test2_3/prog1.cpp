#include <iostream>

using namespace std;

extern const double pi;

void prog1()
{
    std::cout << "in " << __FILE__ << " , " << __FUNCTION__ << " at line: " << __LINE__ << std::endl;
    std::cout << pi << std::endl;
}

constexpr double PI()
{
    return 3.1415926;
}

