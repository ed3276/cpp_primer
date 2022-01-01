#ifndef UTILITY_H_INCLUDED
#define UTILITY_H_INCLUDED
#include <vector>
int Euclid(int m, int n);

int Search(int *L, int size, int x);

/*
 *    ���룺����L[1..n],��Ԫ�ذ��մ�С�������У���x
 *    �������x��L�У����x��λ���±�j(�±��0��ʼ)
 *          ���򷵻�-1
 */
int BinarySearch(std::vector<int> &T, int x);

/*
 *    ���룺ʵ��a, ��Ȼ��n
 *    �����power(a, n)
 *
 */
 long double Power(long double a, int n);

  /*
  *    ���룺������n
  *    �����Fibonacci(n)
  *
  */
unsigned long long Fibonacci(unsigned long long n);

 /*
  *    ���룺����A��B
  *    �����C = A �� B
  *
  */
std::vector<int> intersection(std::vector<int> &A, std::vector<int> &B);


/*
 *
 *    ����S��ѡ��k���Ԫ�أ������k���Ԫ��
 *
 */
int Select(std::vector<int> S, size_t k);

#endif // UTILITY_H_INCLUDED
