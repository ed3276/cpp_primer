#include <vector>
#include <algorithm>
#include <iostream>
/*
 *  输入：非负整数m, n，其中m ，n 不全为零
 *  输出：m与n的最大公约数
 *
 */
int Euclid(int m, int n)
{
    while (m > 0){
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}


/*
 *    输入：数组L[1..n],其元素按照从小到大排列，数x
 *    输出：若x在L中，输出x的位置下标j(下标从0开始)
 *          否则返回-1
 */
int Search(int *L, int size, int x)
{
    int j = 0;
    while (j < size && x > L[j])
        ++j;
    if (j >= size || x < L[j])
        j = -1;
    return j;
}


/*
 *    输入：数组L[1..n],其元素按照从小到大排列，数x
 *    输出：若x在L中，输出x的位置下标j(下标从0开始)
 *          否则返回-1
 */
int BinarySearch(std::vector<int> &T, int x)
{
    int l = 0, r = T.size()-1, m = 0;
    while(l <= r)
    {
        m = (l + r)/2;
        if(T[m] == x)
            return m;
        else if(T[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

/*
 *    输入：实数a, 自然数n
 *    输出：power(a, n)
 *
 */
 long double Power(long double a, int n)
 {
     if (n < 0) { a = 1.0L/a; n = -n;}
     if (n == 0) return 1.0L;
     if (n == 1) return a;
     int d = n / 2, r = n % 2;
     long double t = Power(a, d);
     t = t * t;
     if (r) t = t * a;
     return t;
 }

 /*
  *    输入：正整数n
  *    输出：Fibonacci(n)
  *
  */
unsigned long long Fibonacci(unsigned long long n)
{
  unsigned long long F0 = 0ULL;
  unsigned long long F1 = 1ULL;
  if (n == 0) return F0;
  if (n == 1) return F1;
  unsigned long long F = 0ULL;
  while(--n > 0) {
    F = F1;
    F1 = F0 + F1;
    F0 = F;
  }
  return F1;
}

 /*
  *    输入：集合A与B
  *    输出：C = A 交 B
  *
  */
std::vector<int> intersection(std::vector<int> &A, std::vector<int> &B)
{
    std::vector<int> ans;
    std::vector<int> *pA = &A, *pB = &B;
    if(pA->size() < pB->size())
        swap(pA, pB);
    std::vector<int> Bc(*pB);
    std::sort(Bc.begin(), Bc.end());
    for(std::vector<int>::iterator it = pA->begin(); it != pA->end(); ++it){
        int t = BinarySearch(Bc, *it);
        if(t != -1)
            ans.push_back(Bc[t]);
    }
    return ans;
}

/*
 *
 *    集合S中选第k大的元素，输出第k大的元素
 *
 */
#define NDEBUG
#define NN 5
int Select(std::vector<int> S, size_t k)
{
    if (S.size() <= NN) {
        sort(S.begin(), S.end());
        return S[k-1];
    }
    size_t groupNum = (S.size() + (NN-1)) / NN;   // ceiling of n/5
    std::vector<int> M;
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
    std::vector<int> S1, S2;
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
#undef NDEBUG
#undef NN
