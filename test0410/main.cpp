#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <deque>
#include <queue>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    stack<int, deque<int>> intStack;
    for (size_t ix = 0; ix != 10; ++ix)
    {
        intStack.push(ix);
    }
    while (!intStack.empty())
    {
        int value = intStack.top();
        cout << value << endl;
        intStack.pop();
    }

    {
        cout << "queue" << endl;
        queue<int> intQue;
        intQue.push(2);
        intQue.push(15);
        intQue.emplace(8);
        intQue.emplace(3);
        while(!intQue.empty())
        {
            int value = intQue.front();
            cout << value << endl;
            intQue.pop();
        }
    }

    {
        cout << "priority_queue" << endl;
        priority_queue<int> intPriQue;
        intPriQue.push(2);
        intPriQue.push(15);
        intPriQue.emplace(8);
        intPriQue.emplace(3);
        while(!intPriQue.empty())
        {
            int value = intPriQue.top();
            cout << value << endl;
            intPriQue.pop();
        }
    }
    return 0;
}
