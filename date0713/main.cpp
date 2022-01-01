#include <iostream>
#include <string>
using namespace std;

namespace NS {
    class Quote { /*... */ };
    void display(const Quote&) { /*...*/ }
}
class Bulk_item : public NS::Quote { /*...*/ };

namespace libs_R_us {
    extern void print(int);
    extern void print(double);
}
void print(const std::string &);

using namespace libs_R_us;

void print(int) { }
void fooBar(int ival)
{
    print("Value: ");
    ::print(ival);
}

namespace AW {
    int print(int) { }
}
namespace Primer {
    double print(double) { }
}
using namespace AW;
using namespace Primer;
long double print(long double) { }

namespace primerLib {
    void compute() { cout << "void compute()" << endl; }
    void compute(const void *) { cout << "void compute(const void *)" << endl; }
}
void compute(int) { cout << "void compute(int)" << endl; }
void compute(double, double = 3.14) { cout << "void compute(double, double = 3.14)" << endl; }
void compute(char*, char* = 0) { cout << "void compute(char*, char* = 0)" << endl; }

void f()
{
    using primerLib::compute;
    compute(0);
}

int main()
{
    cout << "Hello world!" << endl;
    string s1, s2;
    swap(s1, s2);
    {
        Bulk_item book1;
        display(book1);
    }
    fooBar(5);
    {
        libs_R_us::print(1);
        Primer::print(3.1);
    }
    f();
    return 0;
}


void print(const std::string &) { }
void libs_R_us::print(int) { }
void libs_R_us::print(double) { }
