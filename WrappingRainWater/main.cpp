#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<vector<int>> F(n, vector<int>(n, 0));
        for (int r = 3; r <= n; ++r) {
            for (int i = 0; i <= n-r; ++i) {
                int j = i + r -1;
                int min_ij = min(height[i], height[j]);
                vector<int>::iterator max_ij_it = max_element(height.begin()+i+1, height.begin()+j);
                if (*max_ij_it >= min_ij) {
                    int tj = max_ij_it-height.begin();
                    F[i][j] = F[i][tj] + F[tj][j];
                }
                else {
                    F[i][j] = min(height[i], height[j])*(j-i-1);
                    for_each(height.begin()+i+1, height.begin()+j, [&](int &e){ F[i][j] -= e; });
                }
            }
        }
        return F[0][n-1];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    vector<int> ex{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << Solution().trap(ex);
    return 0;
}


/*
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<vector<int>> F(n, vector<int>(n, 0));
        vector<vector<int>> S(n, vector<int>(n, 0));
        vector<vector<int>> M(n, vector<int>(n, 0));
        vector<vector<int>> p(n, vector<int>(n, 0));
        for (int i = 0; i != n-1; ++i) {
            S[i][i] = M[i][i] = height[i];
            p[i][i] = i;
            S[i][i+1] = S[i][i] + height[i+1];
            if (height[i+1] > M[i][i]) {
                M[i][i+1] = height[i+1];
                p[i][i+1] = i+1;
            }
            else{
                M[i][i+1] = M[i][i];
                p[i][i+1] = i;
            }
        }
        S[n-1][n-1] = height[n-1];
        for (int r = 3; r <= n; ++r) {
            for (int i = 0; i <= n-r; ++i) {
                int j = i + r -1;
                S[i][j] = S[i][j-1] + height[j];
                if (height[j] > M[i][j-1]) {
                    M[i][j] = height[j];
                    p[i][j] = j;
                }
                else{
                    M[i][j] = M[i][j-1];
                    p[i][j] = p[i][j-1];
                }
                int min_ij = min(height[i], height[j]);
                if (M[i+1][j-1] >= min_ij) {
                    F[i][j] = F[i][p[i+1][j-1]] + F[p[i+1][j-1]][j];
                }
                else {
                    F[i][j] = min(height[i], height[j])*(j-i-1) - S[i+1][j-1];
                }
            }
        }
        return F[0][n-1];
    }
};

*/
