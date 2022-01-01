#ifndef COMMON_H
#define COMM_H
#include <iostream>
using std::cout;
using std::endl;

#define PRINTC(c) \
    for (auto it = c.begin(); it != c.end(); ++it)\
        cout << *it << " ";\
    cout << endl

#define PRINTV(v) \
        cout << v << " ";\
        cout << endl

#define RPRINTC(b, e) \
    for (auto it = b; it != e; ++it)\
        cout << *it << " ";\
    cout << endl;
#endif // COMMON_H
