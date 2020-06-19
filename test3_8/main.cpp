#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string str("Hello");
    std::cout << sizeof(string) << std::endl;
    std::cout << sizeof(str) << std::endl;

    int j = 10, i = 4;
    double no_castd = j / i;
    std::cout << "j / i = " << no_castd << std::endl;
    no_castd = static_cast<double> (j) / i;
    std::cout << "static_cast<double>(j) / i = " << no_castd << std::endl;
    return 0;
}
