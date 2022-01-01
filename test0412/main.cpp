#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<vector<bool>>> &g, vector<vector<vector<bool>>> &visit, int z, size_t i, size_t j, size_t k)
{
    size_t d1 = g.size(), d2 = g[0].size(), d3 = g[0][0].size();
    if (i >= d1 || j >= d2 || k >= d3 || visit[i][j][k]) return;
    visit[i][j][k] = true;
    if (z == g[i][j][k])
    {
        dfs(g, visit, z, i, j, k+1);
        dfs(g, visit, z, i, j, k-1);
        dfs(g, visit, z, i, j+1, k);
        dfs(g, visit, z, i, j-1, k);
        dfs(g, visit, z, i+1, j, k);
        dfs(g, visit, z, i-1, j, k);
    }
    else
        visit[i][j][k] = false;
}

int detectFaces(vector<vector<vector<bool>>> &g)
{
    int faces = 0;
    size_t d1 = g.size(), d2, d3;
    if (d1 != 0)
        d2 = g[0].size();
    else
        return faces;
    if (d2 != 0)
        d3 = g[0][0].size();
    else
        return faces;
    vector<vector<vector<bool>>> visit(d1, vector<vector<bool>>(d2, vector<bool>(d3, false)));
    for (size_t i = 0; i != d1; ++i)
    {
        for (size_t j = 0; j != d2; ++j)
        {
            for (size_t k = 0; k != d3; ++k)
            {
                if (!visit[i][j][k])
                {
                    if (g[i][j][k])
                    {
                        ++faces;
                        dfs(g, visit, 1, i, j, k);
                    }
                    else
                        dfs(g, visit, 0, i, j, k);
                }

            }
        }
    }

    return faces;
}

int main()
{
    cout << "Hello world!" << endl;
    vector<vector<vector<bool>>> g{
        {
            { 1, 0},
            { 0, 1},
        },
        {
            { 0, 1},
            { 1, 0},
        },
        };
    vector<vector<vector<bool>>> g2{
    {
        { 1, 0, 1},
        { 0, 0, 1},
        { 1, 1, 0},
    },
    {
        { 1, 0, 0},
        { 0, 0, 1},
        { 1, 0, 1},
    },
    {
        { 1, 0, 1},
        { 0, 1, 0},
        { 1, 0, 0},
    },
    };
    vector<vector<vector<bool>>> g3{
    {
        { 1, 0, 1},
        { 0, 1, 0},
        { 1, 0, 1},
    },
    {
        { 0, 1, 0},
        { 1, 0, 1},
        { 0, 1, 0},
    },
    {
        { 1, 0, 1},
        { 0, 1, 0},
        { 1, 0, 1},
    },
    };
    vector<vector<vector<bool>>> g4{
    {
        { 1, 1, 1},
        { 1, 1, 1},
        { 1, 1, 1},
    },
    {
        { 1, 1, 1},
        { 1, 1, 1},
        { 1, 1, 1},
    },
    {
        { 1, 1, 1},
        { 1, 1, 1},
        { 1, 1, 1},
    },
    };
    vector<vector<vector<bool>>> g5{
    {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
    },
    {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
    },
    {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
    },
    };
    vector<vector<vector<bool>>> g6{
    {
        { 0, 0, 0},
        { 0, 0, 1},
        { 0, 1, 1},
    },
    {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 1},
    },
    {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
    },
    };
    vector<vector<vector<bool>>> g7{
    {
        { 0, 0, 0},
        { 1, 0, 1},
        { 0, 0, 0},
    },
    {
        { 0, 0, 0},
        { 1, 1, 1},
        { 0, 0, 0},
    },
    {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
    },
    };
    vector<vector<vector<bool>>> g8{
    {
        { 1, 0, 1},
        { 1, 0, 1},
        { 1, 1, 1},
    },
    {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
    },
    {
        { 0, 0, 0},
        { 0, 0, 0},
        { 0, 0, 0},
    },
    };
    cout << detectFaces(g3);
    return 0;
}
