#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string s("some thing!");
    std::cout << s << std::endl;
    if(s.begin() != s.end())
    {
        auto it = s.begin();
        *it = toupper(*it);
    }
    std::cout << s << std::endl;
    return 0;
}
