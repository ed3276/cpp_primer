#include <iostream>
#include <string>
#include <list>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class HasPtr
{
public:
    HasPtr(const char *s) :
        ps(new std::string(s)), i(0) { }
    HasPtr(const std::string &s = std::string()) :
        ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp) {
        ps = new std::string(*hp.ps);
        i = hp.i;
    }
    HasPtr& operator= (const HasPtr &hp){
        if (this == &hp) return *this;
        delete ps;
        ps = new std::string (*hp.ps);
        i = hp.i;
        return *this;
    }
    ~HasPtr() { delete ps; cout << "destory object" << endl; }
private:
    std::string *ps;
    int i;
};

class Foo{
    //Foo(const Foo&) { }
    //默认构造函数Foo() { }
    //合成拷贝构造函数Foo(const Foo &) { }
    //合成赋值运算符Foo& operator= (const Foo&) { }
    //合成析构函数~Foo() { }
};

struct X{
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator= (const X&) { std::cout << "X& operator= (const X&)" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void fx(X x) { std::cout << "void fx(X x)" << std::endl; }
void fxc(X &x) { std::cout << "void fxc(X &x)" << std::endl; }

struct numbered {
    numbered() : mysn(rand()) { std::cout << "nembered() : " << mysn << std::endl; }
    numbered(numbered &n) {
        mysn = rand();
        std::cout << "nembered(numbered &n) : " <<  mysn << std::endl;
    }
    size_t mysn;
};

void f_n(numbered &s) { std::cout << "f_n(numbered &s) : " << s.mysn << std:: endl; }

class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const Sales_data&) = default;
    Sales_data& operator= (const Sales_data&);
    ~Sales_data() = default;
};

Sales_data& Sales_data::operator= (const Sales_data&) = default;   //不是内联的

int main()
{
    srand(time(nullptr));
    cout << "Hello world!" << endl;
    HasPtr hp1;
    hp1 = hp1 = hp1;
    {
        HasPtr hp2;
        hp2 = hp1;
    }
    //HasPtr p10[1000];
    //list<HasPtr> plist{"hsf", "dfd", "ood"};
    //HasPtr *hpp1 = new HasPtr[10];
    //delete [] hpp1;
    {
        shared_ptr<HasPtr> sphp = make_shared<HasPtr>();
    }
    Foo f;
    f = f;
    Foo f2 = f;
    f2.operator=(f);
    {
        {
            X x;
            fx(x);
            fxc(x);
        }
        {
            std::cout << "--------Dynamic allocator--------" << std::endl;
            X *px = new X;
            delete px;
            std::cout << "****" << std::endl;
            X *parr = new X[3];
            delete [] parr;
            std::cout << "****" << std::endl;
            allocator<X> alloc;
            X *pa = alloc.allocate(10);
            X *ppa = pa;
            alloc.construct(ppa++, X());
            std::cout << "+++" << std::endl;
            while(ppa != pa)
                alloc.destroy(--ppa);
            alloc.deallocate(pa, 10);

        }
        {
            std::cout << "--------Containor--------" << std::endl;
            {
                std::cout << "-----vector-----" << std::endl;
                vector<X> lx(3);
            }

                std::cout << "-----list-----" << std::endl;
                X x;
                list<X> lx{X()};
            }
        }
        {
            std::cout << "--------numbered--------" << std::endl;
            numbered a, b = a, c = b;
            f_n(a); f_n(b); f_n(c);
        }
    return 0;
}
