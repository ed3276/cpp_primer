#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int Select(vector<int> S, size_t k)
{
    if (S.size() <= 5) {
        sort(S.begin(), S.end());
        return S[k-1];
    }
    size_t groupNum = (S.size() + 4) / 5;   // ceiling of n/5
    vector<int> M;
    for (size_t i = 0; i != groupNum; ++i) {
        auto b = S.begin()+5*i, e = S.begin()+5*(i+1);
        if(i == groupNum-1) e = S.end();
        auto m = b + (e - b)/2;
        sort(b, e);
        M.push_back(*m);
    }
    int mv = Select(M, (M.size()+1)/2);  // ceiling of |M|/5
    vector<int> S1, S2;
    for (size_t i = 0; i != groupNum; ++i) {
        auto b = 5*i, e = 5*(i+1);
        if(i == groupNum-1) e = S.size();
        auto m = 5*i + (e - b)/2;
        if (S[m] < mv) {
            for(size_t kk = b; kk <= m; ++kk)
                S1.push_back(S[kk]);
            for(size_t kk = m+1; kk != e; ++kk){
                if (S[kk] < mv) S1.push_back(S[kk]);
                else S2.push_back(S[kk]);
            }
        }
        else if(S[m] == mv){
            for(size_t kk = b; kk != m; ++kk)
                S1.push_back(S[kk]);
            for(size_t kk = m+1; kk != e; ++kk)
                S2.push_back(S[kk]);
        }
        else {
            for(size_t kk = m; kk != e; ++kk)
                S2.push_back(S[kk]);
            for(size_t kk = b; kk != m; ++kk){
                if (S[kk] < mv) S1.push_back(S[kk]);
                else S2.push_back(S[kk]);
            }
        }
    }
    if (k == S1.size()+1 ) return mv;
    else if(k <= S1.size()){
        return Select(S1, k);
    }
    else{
        return Select(S2, k - S1.size() - 1);
    }
}

void InsertSort(vector<int> &A)
{
    int n = A.size();
    int x;
    int j;
    for (int i = 1; i != n; ++i){
        x = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > x){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = x;
    }
}

int BinaryFind(const vector<int> &A, int s, int e, int x)
{
    int m;
    while (s <= e){
        m = s + (e - s)/2;
        if (A[m]  <= x)
            s = m + 1;
        else
            e = m - 1;
    }
    return s;
}
int BinaryFindL(const vector<int> &A, int s, int e, int x)
{
    int m;
    while (s <= e){
        m = s + (e - s)/2;
        if (A[m]  < x)
            s = m + 1;
        else
            e = m - 1;
    }
    return s;
}
void ModInsertSort(vector<int> &A)
{
    int n = A.size();
    int x, j, k;
    for (int i = 1; i != n; ++i){
        x = A[i];
        j = i - 1;
        k = BinaryFind(A, 0, j, x);
        while (j >= k){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[k] = x;
    }
}

int partition(vector<int> &A, int p, int r)
{
    int &pivot = A[r];
    int i = p - 1;
    for (int j = p; j != r; ++j){
        if (A[j] < pivot){
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], pivot);
    return i+1;
}
void QuickSort(vector<int> &A, int p, int r)
{
    if (p < r){
        int q = partition(A, p, r);
        QuickSort(A, p, q-1);
        QuickSort(A, q+1, r);
    }
}

int i = 0;
void move(char A, char C)
{
    ++i;
    cout << i << "\t. move " << A << " to " << C << " " << endl;
}
void Hanoi(char A, char B, char C, int n)
{
    if (n == 1){
        move(A, C);
    }
    else{
        Hanoi(A, C, B, n-1);
        move(A, C);
        Hanoi(B, A, C, n-1);
    }
}
void DHanoi(char A, char B, char C, int n)
{
    if (n == 1){
        move(A, C);
        move(A, C);
    }
    else{
        DHanoi(A, C, B, n-1);
        move(A, C);
        move(A, C);
        DHanoi(B, A, C, n-1);
    }
}

int main()
{
    cout << "Hello world!" << endl;
    #if 0
    vector<int> S{5,45,8,7,59,32,45,203,0,-65};
    cout << Select(S, S.size()/3) << endl;
    sort(S.begin(), S.end());
    cout << S[S.size()/3 -1] << endl;
    #endif
    const int n(200000);
    vector<int> S0(n);
    iota(S0.begin(), S0.end(), 1);
    random_shuffle(S0.begin(), S0.end());
    //for_each(S0.begin(), S0.end(), [](int e) { cout << e << "  "; }); cout << endl;
    //cout << Select(S0, 10) << endl;
    //ModInsertSort(S0);
    //InsertSort(S0);
    QuickSort(S0, 0, S0.size()-1);
    //for_each(S0.begin(), S0.end(), [](int e) { cout << e << "  "; }); cout << endl;
    DHanoi('A', 'B', 'C', 4);
    vector<int> v2{-1,9,8,6,7,2,2,2,6,963,2,2,2};
    sort(v2.begin(), v2.end());
    for_each(v2.begin(), v2.end(), [](int e) { cout << e << "  "; }); cout << endl;
    cout << BinaryFind(v2, 0, v2.size(), 2) << endl;
    cout << BinaryFindL(v2, 0, v2.size(), 2) << endl;
    return 0;
}
