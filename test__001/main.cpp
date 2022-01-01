#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    cout << max(12, 45) << endl;
    vector<int> iv{12, 56, 99, 55, 123};
    cout << *max_element(iv.begin(), iv.end()) << endl;
    {
        unsigned long quiz1 = 0;
        quiz1 |= 1UL << 27;
        bool status = quiz1 & (1UL << 27);
        cout << (status ? "27 pass." : "27 fail") << endl;
        quiz1 &= ~(1UL << 27);
        status = quiz1 & (1UL << 27);
        cout << (status ? "27 pass." : "27 fail") << endl;
    }
    {
        double *p1;
        int *p2;
        vector<int> *p3;
        cout << sizeof *p1 << endl;
        cout << sizeof *p2 << endl;
        cout << sizeof *p3 << endl;
        cout << sizeof (vector<int>) << endl;
        cout << sizeof (vector<double>) << endl;
        cout << sizeof (string) << endl;
    }
    {
        cout << "bool: " << sizeof (bool) << endl;
        cout << "char: " << sizeof (char) << endl;
        cout << "unsigned char: " << sizeof (unsigned char) << endl;
        cout << "signed char: " << sizeof (signed char) << endl;
        cout << "short: " << sizeof (short) << endl;
        cout << "unsigned int: " << sizeof (unsigned int) << endl;
        cout << "int: " << sizeof (int) << endl;
        cout << "long int: " << sizeof (long int) << endl;
        cout << "unsigned long int: " << sizeof (unsigned long int) << endl;
        cout << "long long int: " << sizeof (long long int) << endl;
        cout << "unsigned long long int: " << sizeof (unsigned long long int) << endl;
        cout << "float: " << sizeof (float) << endl;
        cout << "double: " << sizeof (double) << endl;
        cout << "double &: " << sizeof (double &) << endl;
        cout << "double *: " << sizeof (double *) << endl;
        cout << "int *: " << sizeof (int *) << endl;
        cout << "decltype(8): " << sizeof (decltype(8.2)) << endl;
        //cout << "void: " << sizeof (void) << endl;
    }
    {
        int ia[10];
        constexpr size_t sz = sizeof ia / sizeof (*ia);
         int arr1[sz];
    }
    {
        char ch1 = 0xff;
        cout << (int) ch1 << endl;
        cout << ch1 + 1 << endl;
        unsigned char ch2 = 0xff;
        cout << (int) ch2 << endl;
        cout << ch2 + 1 << endl;
    }
    {
        int arr[10];
        decltype (arr) arr2;
        cout << sizeof (arr2) << endl;
        int (*parr)[10] = &arr;

        //cout << typeid (int) << endl;
    }
    {
        int *p = 0;
        vector<int> **vp = 0;
        string **********************sp = nullptr;
    }
    {
        int i = 885555 , j = 2;
        double slope = static_cast<double>(i) / j;
        void *p = &i;
        char ch = i;
        int *ii = static_cast<int*>(p);
    }
    return 0;
}
