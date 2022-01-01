#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

using LCSans = tuple<vector<vector<int>>, vector<vector<int>>>;
LCSans LCS(string &X, string &Y)
{
    int m = X.length(), n = Y.length();
    tuple_element<0, LCSans>::type C(m+1, vector<int>(n+1, 0)), B(C);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i-1] == Y[j-1]) {
                C[i][j] = C[i-1][j-1] + 1;
                B[i][j] = 'D';
            }
            else {
                if (C[i-1][j] >= C[i][j-1]) {
                    C[i][j] = C[i-1][j];
                    B[i][j] = 'U';
                }
                else {
                    C[i][j] = C[i][j-1];
                    B[i][j] = 'L';
                }
            }
        }
    }
    return make_tuple(C, B);
}
void StructureSequence(string &X, int m, int n, LCSans &lcsans, string &solve)
{
    if (m == 0 || n == 0) return;
    tuple_element<1, LCSans>::type &C = get<1>(lcsans);
    if (C[m][n] == 'D') {
        solve.insert(solve.begin(), X[m-1]);
        StructureSequence(X, m-1,  n-1, lcsans, solve);
    }
    else if (C[m][n] == 'U') {
        StructureSequence(X, m-1,  n, lcsans, solve);
    }
    else {
        StructureSequence(X, m,  n-1, lcsans, solve);
    }
}
int main()
{
    cout << "Hello world!" << endl;
    string X{'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    string Y{'B', 'D', 'C', 'A', 'B', 'A'};
    LCSans ans = LCS(X, Y);
    string Z;
    StructureSequence(X, X.length(), Y.length(), ans, Z);
    cout << Z << endl;
    return 0;
}
