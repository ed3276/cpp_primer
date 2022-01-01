#include <iostream>

using namespace std;
class ZooAnimal { };
class Endangered { };
class Raccoon : public virtual ZooAnimal { };
class Bear : virtual public ZooAnimal { };
class Panda : public Bear, public Raccoon, public Endangered { };

struct Base {
    void bar(int) { }
protected:
    int ival;
};
struct Derived1 : virtual public Base {
    void bar(char) { }
    void foo(char) { }
protected:
    char cval;
};
struct Derived2 : virtual public Base {
    void foo(int) { }
protected:
    int ival;
    char cval;
};
class VMI : public Derived1, public Derived2 {
    void f() { bar(9); Derived1::foo(0); ival;Derived2::cval; }
};

class Class {public:Class(){cout<<"Class()"<<endl;}~Class(){cout<<"~Class()"<<endl;}};
class Base_ : public Class {public:Base_(){cout<<"Base_()"<<endl;}Base_(const Base_&){}Base_(int){}~Base_(){cout<<"~Base_()"<<endl;}};
class D1 : virtual public Base_ {public:D1():Base_(){cout<<"D1()"<<endl;}D1(const D1&d1):Base_(d1){}D1(int i):Base_(i){}~D1(){cout<<"~D1()"<<endl;}};
class D2 : virtual public Base_ {public:D2():Base_(){cout<<"D2()"<<endl;}D2(const D2&d2):Base_(d2){}D2(int i):Base_(i){}~D2(){cout<<"~D2()"<<endl;}};
class MI : public D1, public D2 {public:MI():Base_(){cout<<"MI()"<<endl;}MI(const MI&mi):Base_(mi){}MI(int i):Base_(i){}~MI(){cout<<"~MI()"<<endl;}};
class Final : public MI, public Class {public:Final():Base_(){cout<<"Final()"<<endl;}Final(const Final&fi):Base_(fi){}Final(int i):Base_(i){}~Final(){cout<<"~Final()"<<endl;}};

int main()
{
    cout << "Hello world!" << endl;
    {
        Final final;

        Base *pb;
        Final::Base_::Class *pc;
        MI *pmi;
        D2 *pd2;
        //pb = new Class;
        pc = static_cast<Final::Base_::Class*>(new Final);
        //pmi = pb;
        pd2 = pmi;
    }
    return 0;
}
