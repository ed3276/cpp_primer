#include <iostream>
#include <vector>
using namespace std;

pair<vector<vector<int>>, vector<vector<int>>> KnapsackProblem(int n, vector<int> &w, vector<int> &v, int b)
{
    vector<vector<int>> F(n+1, vector<int>(b+1, 0));
    vector<vector<int>> s(n+1, vector<int>(b+1, 0));
    for (int y = 1; y <= b; ++y) {
        F[1][y] = y/w[0]*v[0];
        s[1][y] = (y >= w[0]) ? 1 : 0;
    }
    for (int k = 2; k <= n; ++k) {
        for (int y = 1; y <=b; ++y) {
            F[k][y] = F[k-1][y];
            s[k][y] = s[k-1][y];
            int tmp = INT_MIN;
            int wt = y - w[k-1];
            if (wt >= 0) {
                tmp = F[k][wt] + v[k-1];
            }
            if (F[k][y] <= tmp) {
                F[k][y] = tmp;
                s[k][y] = k;
            }
        }
    }
    return {F, s};
}

vector<int> trackSolution(int n, vector<int> &w, int b, vector<vector<int>> &s)
{
    vector<int> solve(n, 0);
    int j = n, y = b;
    while (s[j][y] != 0) {
        do {
            j = s[j][y];
            solve[j-1] += 1;
            y -= w[j-1];
        }while (s[j][y] == j);
    }
    return solve;
}
int main()
{
    cout << "Hello world!" << endl;
    int n = 4, b = 10;
    vector<int> w{2,3,4,7}, v{1,3,5,9};
    pair<vector<vector<int>>, vector<vector<int>>>
        ans = KnapsackProblem(n, w, v, b);
    vector<int> s = trackSolution(n, w, b, ans.second);
    cout << ans.first[n][b] << endl;
    for (auto e : s)
        cout << e << " ";
    return 0;
}
