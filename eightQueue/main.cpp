#include <iostream>
#include <vector>

using namespace std;

////8皇后递归实现recursive
void ReBack(int n, vector<int> &Xk, vector<list<int>> Sk, vector<vector<int>> &ans, vector<int> &solve, size_t k)
{
    if(k >= n)
        ans.push_back(solve);
    else
    {
        while(!Sk[k].empty())
        {
            solve[k] = Sk[k][0];
            Sk[k].erase(Sk[k].begin());
            //计算S(k+1)
            Sk[k+1].clear();
            for (size_t c = 0; c != n; ++c)
            {
                //两个皇后不能处于同一列
                size_t j;
                for (j = 0; j <= k; ++j)
                {
                    if(c == solve[j])
                        break;
                }
                if(j > k)
                {
                    int p = k, q = c - 1;
                    //两个皇后不能处于同一副对角线
                    while(p >= 0 && q >= 0)
                    {
                        if( solve[p] == q)
                            break;
                        --p; --q;
                    }
                    if(p < 0 || q < 0)
                    {
                        p = k, q = c + 1;
                        //两个皇后不能处于同一主对角线
                        while(p >= 0 && q < n)
                        {
                            if( solve[p] == q)
                                break;
                            --p; ++q;
                        }
                        if(p < 0 || q >= n)
                             Sk[k+1].push_back(c);
                    }
                }
            }
            ReBack(n, Xk, Sk, ans, solve, k+1);
        }
    }
}
vector<vector<int>> ReBacktrack(int n)
{
    vector<int> solve(n);
    vector<vector<int>> ans;
    vector<int> Xk;
    for (size_t i = 0; i != n; ++i)
        Xk.push_back(i);
    vector<vector<int>> Sk(n);
    Sk[0] = Xk;
    ReBack(n, Xk, Sk, ans, solve, 0);
    return ans;
}


//8皇后迭代实现
vector<vector<int>> Backtrack(int n)
{
    vector<int> solve(n);
    vector<vector<int>> ans;
    vector<int> Xk;
    for (size_t i = 0; i != n; ++i)
        Xk.push_back(i);
    vector<vector<int>> Sk(n);
    int k = 0;
    Sk[k] = Xk;
step4:
    while(!Sk[k].empty())
    {
        solve[k] = Sk[k][0];
        Sk[k].erase(Sk[k].begin());
        if(k < n - 1)
        {
            ++k;
            //计算S(k+1)
            Sk[k].clear();
            for (size_t c = 0; c != n; ++c)
            {
                //两个皇后不能处于同一列
                size_t j;
                for (j = 0; j < k; ++j)
                {
                    if(c == solve[j])
                        break;
                }
                if(j >= k)
                {
                    int p = k - 1, q = c - 1;
                    //两个皇后不能处于同一副对角线
                    while(p >= 0 && q >= 0)
                    {
                        if( solve[p] == q)
                            break;
                        --p; --q;
                    }
                    if(p < 0 || q < 0)
                    {
                        p = k - 1, q = c + 1;
                        //两个皇后不能处于同一主对角线
                        while(p >= 0 && q < n)
                        {
                            if( solve[p] == q)
                                break;
                            --p; ++q;
                        }
                        if(p < 0 || q >= n)
                             Sk[k].push_back(c);
                    }
                }
            }
        }
        else
            ans.push_back(solve);
    }
    if(k > 0)
    {
        --k;
        goto step4;
    }
    return ans;

}
int main()
{
    cout << "Hello world!" << endl;
    int n = 8;
    vector<vector<int>> ans;
    ans = Backtrack(n);
    for(auto e : ans)
    {
        for ( auto ee : e)
            cout << ee << " ";
        cout << endl;
    }
    cout << ans.size() << endl;
    return 0;
}
