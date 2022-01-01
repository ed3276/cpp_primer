#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;

constexpr long double EPS = 1e-10;
constexpr size_t n = 9;
long double value = 123456789.987654321;

long double sqrt_l(long double val)
{
    assert(val >= 0);
    long double b = 0, e = val, m = (b + e)/2;
    size_t n = 0;
    while(1)
    {
        long double t = m * m;
        if(fabs(t - val) < EPS )
            return m;
        else if(t < val)
            b = m;
        else
            e = m;
        m = (b + e)/2;
        cout << setprecision(n) << fixed;
        cout << "Times = " << ++n << ", f( " << m << ", " << m*m << " ), " << "decision = " << m*m-val << "." << endl;
    }
}
long double sqrt_n(long double val)
{
    assert(val >= 0);
    long double x = val, f;
    size_t n = 0;
    cout << setprecision(n) << fixed;
    while(fabs(f = x * x - val) > EPS)
    {
        cout << setprecision(n) << fixed;
        cout << "Times = " << ++n << ", f( " << x << ", " << x*x << " ), " << "decision = " << x*x-val << "." << endl;
        x = (x + val / x) / 2;
    }
    cout << "Times = " << ++n << ", f( " << x << ", " << x*x << " ), " << "decision = " << x*x-val << "." << endl;
    return x;
}
int main()
{
    cout << "Hello world!" << endl;
    cout << setprecision(n) << fixed;
    cout << sqrt_l(value) << endl;
    cout << endl;
    cout << sqrt_n(value) << endl;
    return 0;
}
