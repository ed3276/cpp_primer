#include <iostream>
#include <string>
using namespace std;

std::string screen(std::string::size_type = 10, std::string::size_type = 5, char = 'a');

int main()
{
    cout << "Hello world!" << endl;
    cout << screen() << endl;
    cout << screen(1) << endl;
    cout << screen(5,2) << endl;
    cout << screen(20,2,'A');
    string s("abc");
    return 0;
}


std::string screen(std::string::size_type width, std::string::size_type height, char backgrnd)
{
    std::cout << "width is " << width << std::endl;
    std::cout << "height is " << height << std::endl;
    std::cout << "background is " << backgrnd << std::endl;
    return std::string(width*height,backgrnd);
}
