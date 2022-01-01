#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define NDEBUG
#define NN 5
int Select(vector<int> S, size_t k)
{
    if (S.size() <= NN) {
        sort(S.begin(), S.end());
        return S[k-1];
    }
    size_t groupNum = (S.size() + (NN-1)) / NN;   // ceiling of n/5
    vector<int> M;
    for (size_t i = 0; i != groupNum; ++i) {
        auto b = S.begin()+NN*i, e = S.begin()+NN*(i+1);
        if(i == groupNum-1) e = S.end();
        auto m = b + (e - b)/2;
        sort(b, e);
        M.push_back(*m);
    }
    #ifndef NDEBUG
    cout << "\t";
    cout << "M:(midK=" << (M.size()+1)/2 << ")"; for_each(M.begin(), M.end(), [](int e) { cout << e << "  "; }); cout << endl;
    #endif
    int mv = Select(M, (M.size()+1)/2);  // ceiling of |M|/5
    #ifndef NDEBUG
    cout << "\t";
    cout << "has find target middle number = " << mv << endl;
    cout << "\t";
    cout << "M:(midK=" << (M.size()+1)/2 << ")"; for_each(M.begin(), M.end(), [](int e) { cout << e << "  "; }); cout << endl;
    #endif
    vector<int> S1, S2;
    for (size_t i = 0; i != groupNum; ++i) {
        auto b = NN*i, e = NN*(i+1);
        if(i == groupNum-1) e = S.size();
        auto m = NN*i + (e - b)/2;
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
        #ifndef NDEBUG
        cout << "S1:(size=" << S1.size() << ", chooseK=" << k << ")";
        for_each(S1.begin(), S1.end(), [](int e) { cout << e << "  "; }); cout << endl;
        cout << "S2:(size=" << S2.size() << ")";
        for_each(S2.begin(), S2.end(), [](int e) { cout << e << "  "; }); cout << endl;
        #endif
        return Select(S1, k);
    }
    else{
        #ifndef NDEBUG
        cout << "S1:(size=" << S1.size() << ")";
        for_each(S1.begin(), S1.end(), [](int e) { cout << e << "  "; }); cout << endl;
        cout << "S2:(size=" << S2.size() << ", chooseK=" << k - S1.size() - 1 << ")";
        for_each(S2.begin(), S2.end(), [](int e) { cout << e << "  "; }); cout << endl;
        #endif
        return Select(S2, k - S1.size() - 1);
    }
}



int main()
{
    cout << "Hello world!" << endl;
    #if 1
    vector<int> S{5,45,8,7,59,32,45,203,0,-65};

    cout << Select(S, S.size()/3) << endl;
    sort(S.begin(), S.end());
    cout << S[S.size()/3 -1] << endl;
    #endif
    const int n(10000000);
    vector<int> S0(n);
    iota(S0.begin(), S0.end(), 1);
    #ifndef NDEBUG
    for_each(S0.begin(), S0.end(), [](int e) { cout << e << "  "; });
    cout << endl;
    #endif
    random_shuffle(S0.begin(), S0.end());
    #ifndef NDEBUG
    for_each(S0.begin(), S0.end(), [](int e) { cout << e << "  "; }); cout << endl;
    cout << endl;
    #endif
    cout << Select(S0, 4000000) << endl;
    return 0;
}
