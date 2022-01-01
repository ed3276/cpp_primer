#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED
#include <vector>
int Euclid(int m, int n);

int Search(int *L, int size, int x);

/*
 *    输入：数组L[1..n],其元素按照从小到大排列，数x
 *    输出：若x在L中，输出x的位置下标j(下标从0开始)
 *          否则返回-1
 */
int BinarySearch(std::vector<int> &T, int x);

/*
 *    输入：实数a, 自然数n
 *    输出：power(a, n)
 *
 */
 long double Power(long double a, int n);

  /*
  *    输入：正整数n
  *    输出：Fibonacci(n)
  *
  */
unsigned long long Fibonacci(unsigned long long n);

 /*
  *    输入：集合A与B
  *    输出：C = A 交 B
  *
  */
std::vector<int> intersection(std::vector<int> &A, std::vector<int> &B);


/*
 *
 *    集合S中选第k大的元素，输出第k大的元素
 *
 */
int Select(std::vector<int> S, size_t k);

#endif // UTILITY_H_INCLUDED
