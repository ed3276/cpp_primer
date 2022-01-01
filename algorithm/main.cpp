#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include "utility.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << Euclid(86UL, 9999ULL) << endl;
    int arr[10] = {6, 5, 8, 9, 45, 86, 4, 69, 54, 123};
    sort(begin(arr), end(arr));
    int index = Search(arr, 10, 8236);
    if (index == -1)
        cout << "can not find target number" << endl;
    else
        cout << "have find target number, index = " << index << endl;

    cout << "======Test Power======" << endl;
    cout << Power(2.23, 100) << endl;

    cout << "======Test Fibonacci======" << endl;
    cout << Fibonacci(500) << endl;

    {
        cout << "======Test intersection======" << endl;
        vector<int> A{4,5,9,87,3,12,6,3,85,79};
        vector<int> B{87,666,6,156,5};
        vector<int> C = intersection(A, B);
        for(auto e : C)
            cout << e << " ";
        cout << endl;
    }

    {
        cout << "======Test 2.14======" << endl;
        vector<int> S{5,45,8,7,59,32,45,203,0,98};
        int pivot = Select(S, S.size()/2);
        partition(S.begin(), S.end(), [&](int e){ return e <= pivot; });
        vector<int> S1(S.begin(), S.begin()+S.size()/2);
        vector<int> S2(S.begin()+S.size()/2+1, S.end());
        int sumS1 = accumulate(S1.begin(), S1.end(), 0);
        int sumS2 = accumulate(S2.begin(), S2.end(), 0);
        for (auto e : S)
            cout << e << " ";
        cout << endl;
        cout << sumS2 - sumS1 <<endl;

    }

    return 0;
}
