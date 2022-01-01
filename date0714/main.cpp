#include <iostream>

using namespace std;

class A {public: A(){ cout << "A()" << endl;} ~A(){ cout << "~A()" << endl;}};
class B : public A {public: B(){ cout << "B()" << endl;} ~B(){ cout << "~B()" << endl;} };
class C : public B {public: C(){ cout << "C()" << endl;}~C(){ cout << "~C()" << endl;} };
class X {public: X(){ cout << "X()" << endl;}~X(){ cout << "~X()" << endl;} };
class Y {public: Y(){ cout << "Y()" << endl;}~Y(){ cout << "~Y()" << endl;} };
class Z : public X, public Y {public: Z(){ cout << "Z()" << endl;}~Z(){ cout << "~Z()" << endl;} };
class MI : public C, public Z {public: MI(){ cout << "MI()" << endl;}~MI(){ cout << "~MI()" << endl;} };

class D : public X, public C { };

class Base1 {public: virtual void print(){cout << "Base1::print()" << endl;}virtual ~Base1(){cout << "Base1::~Base1()" << endl;}};
class Base2 {public: virtual void print(){cout << "Base2::print()" << endl;}virtual ~Base2(){cout << "Base2::~Base2()" << endl;}};
class D1 : public Base1 {public: void print(){cout << "D1::print()" << endl;}~D1(){cout << "D1::~D1()" << endl;}};
class D2 : public Base2 {public: void print(){cout << "D2::print()" << endl;}~D2(){cout << "D2::~D2()" << endl;}};
class Mi : public D1, public D2 {public: void print(){cout << "Mi::print()" << endl;}~Mi(){cout << "Mi::~Mi()" << endl;}};
int main()
{
    cout << "Hello world!" << endl;
    MI mi;
    {
        D *pd = new D;
        X *px = pd;
        A *pa = pd;
        B *pb = pd;
        C *pc = pd;
    }
    {
        cout << endl << endl;
        Base1 *pb1 = new Mi;
        Base2 *pb2 = new Mi;
        D1 *pd1 = new Mi;
        D2 *pd2 = new Mi;
        {
            cout << "(a): " << endl;
            pb1->print();
            cout << "(b): " << endl;
            pd1->print();
            cout << "(c): " << endl;
            pd2->print();
            cout << "(d): " << endl;
            delete pb1;
            cout << "(e): " << endl;
            delete pd1;
            cout << "(f): " << endl;
            delete pd2;
        }
    }
    return 0;
}
