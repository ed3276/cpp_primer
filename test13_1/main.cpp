#include <iostream>

using namespace std;

class Foo
{
public:
    Foo();
    Foo(int);
    //Foo(Foo &);
    //Foo(const Foo &);
    ~Foo(){cout << "deconstructor" << a << endl;}
    Foo& operator=(const Foo&);
    void data()const {cout << a << endl;}
private:
    int a={99};

};

int main()
{
    cout << "Hello world!" << endl;
    Foo f=88;
    f.data();
    cout << endl << endl << endl;
    Foo f2=f;
    f2.data();
    cout << endl << endl << endl;
    f2=97;
    f2.data();
    return 0;
}
#if 1
Foo::Foo():a(10)
{
    cout << "defualt constructor" <<endl;
}
/*Foo::Foo(Foo& cf):a(cf.a)
{
    cout << "copy  constructor" <<endl;
}
Foo::Foo(const Foo& cf):a(cf.a)
{
    cout << "copy const constructor" <<endl;
}*/
Foo::Foo(int c)
{
    a = c;
    cout << "direct constructor" <<endl;
}
Foo& Foo::operator=(const Foo& f)
{
    a = f.a;
    cout << "copy assignment operator" <<endl;
    return *this;
}
#endif
