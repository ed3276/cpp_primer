#include <iostream>
#include "Screen.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    Screen myScreen(5,5,'X');
    myScreen.moves(4,0).set('#').display(std::cout);
    cout << "\n";
    myScreen.display(std::cout).moves(4,1).set('@').display(std::cout);
    cout << "\n";
    return 0;
}
