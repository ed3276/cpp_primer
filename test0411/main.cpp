#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <list>
#include <deque>
#include <forward_list>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    int value = 42;
    vector<int> vi{27, 210, 12, 42, 47, 109, 83};
    auto result = find(vi.begin(), vi.end(), value);
    cout << "The value " << value
         << (result == vi.end()
         ? " is not present" : " is present") << endl;

    int ia[] = {1, 2, 8};
    cout << accumulate(begin(ia), end(ia), 0) << endl;

    /*
    list<string> listr;
    string s;
    while (cin >> s)
        listr.insert(listr.end(), s);
    string sum = accumulate(listr.begin(), listr.end(), string(""));
    cout << sum << endl;
    */

    {
        vector<int> vi{2, 5, 98};
        deque<int> di{2, 5, 98, 99};
        bool ans = equal(vi.begin(), vi.end(), di.begin());
        cout << "1: " << ans << endl;
        vector<const char*> vs{"ab", "cd", "zz"};
        forward_list<const char*> fcc{"ab", "cd", "zz", "ad"};
        ans = equal (vs.begin(), vs.end(), fcc.begin());
        cout << "2: " << ans << endl;
    }
    {
        vector<double> vd{9.9, 1.2};
        cout << accumulate(vd.begin(), vd.end(), 0) << endl;
    }
    return 0;
}
