#include <iostream>
#include <utility>
#include <sstream>
#include <memory>
using namespace std;

template <typename T> void f3(T&& p) { T t = p; t = t + 1; cout << "t = " << t << endl; }

template <typename T>
typename remove_reference<T>::type &&moving(T&& t)
{
    return static_cast<typename remove_reference<T>::type &&>(t);
}
template <typename T1, typename T2>
typename add_rvalue_reference<T1>::type &&forwarding(T2 &&t)
{
    return static_cast<typename add_rvalue_reference<T1>::type &&>(t);
}
void f(int v1, int &v2)
{
    cout << v1 << " " << ++v2 << endl;
}
void g(int &&i, int &j)
{
    cout << i << " " << j << endl;
}
template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
    f(t2, t1);
}
template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
    //f(std::forward<T2>(t2), std::forward<T1>(t1));
    f(forwarding<T2>(t2), forwarding<T1>(t1));
}

//÷ÿ‘ÿ”Îƒ£∞Â
template <typename T> string debug_rep(const T &t)
{
    cout << "call func@@ string debug_rep(const T &t) @@" << endl;
    ostringstream ret;
    ret << t;
    return ret.str();
}
template <typename T> string debug_rep(T *p)
{
    cout << "call func@@ string debug_rep(T *p) @@" << endl;
    ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}

string debug_rep(char *p)
{
    cout << "call func@@ debug_rep(char *p) @@" << endl;
    return debug_rep(string(p));
}
string debug_rep(const char *p)
{
    cout << "call func@@ debug_rep(const char *p) @@" << endl;
    return debug_rep(string(p));
}
string debug_rep(const string &s)
{
    cout << "call func@@ debug_rep(const string &s) @@" << endl;
    return '"' + s + '"';
}
//==========

//exercise 16.49
template <typename T> void ff(T) { cout << "call func@@ void f(T) @@" << endl; }
template <typename T> void ff(const T*) { cout << "call func@@ void f(const T*) @@" << endl; }
template <typename T> void gg(T) { cout << "call func@@ void g(T) @@" << endl; }
template <typename T> void gg(T*) { cout << "call func@@ void g(T*) @@" << endl; }

//variadic template
template <typename U, typename... T>
void foo(const U &u, const T& ...t) { cout << sizeof...(T) << endl; cout << sizeof...(t) << endl; }

//template <typename T>
//ostream &print(ostream& os, const T &t);
ostream &print(ostream &os) { return os; }
template <class T, class W, typename ... U>
ostream &print(ostream& os, const T &t, const W &w, const U& ...u)
{
    cout << sizeof...(U) << " || " << sizeof...(u) << endl;
    cout << "+++++.. ostream &print(ostream& os, const T &t, const U& ...u) ..+++++++" << endl;
    os << t << " | " << w << " | ";
    return print(os, u...);
}

template <typename T>
ostream &print(ostream& os, const T &t)
{
    cout << "+++++.. ostream &print(ostream& os, const T &t) ..+++++++" << endl;
    os << t << endl;
    return os;
}

class VV{};

void error_msg(initializer_list<string> il)
{
    for (auto beg = il.begin(); beg != il.end(); ++beg)
        cout << *beg << " ";
    cout << endl;
}

template <typename T, typename... Args>
ostream &errorMsg(ostream &os, const T& t, const Args&... args)
{
    return print(os, debug_rep(args)...);
}

template <typename T, typename ... Args>
void emplace(Args&& ... args)
{
    T(std::forward<Args>(args) ...);
}

int main()
{
    cout << "Hello world!" << endl;

    {
        int i; const int ci = 9;
        ((((i)))) = 0;
        {
            int &ri1 = i;
            //int &ri2 = ci;
            //int &ri3 = i * 42;
            //int &ri4 = 42;
        }
        {
            const int &rci1 = i;
            const int &rci2 = ci;
            const int &rci3 = i* 42;
            const int &rci4 = 42;
        }
        {
            //int &&rri1 = i;
            int &&rri1 = static_cast<int&&>(i);
            //int &&rri2 = ci;
            int &&rri3 = int();
            int &&rri4 = 42;
            rri4 = 32;
            cout << "rri3 = " << rri3 << endl;
            f3((rri3+0));
            cout << "rri3 = " << rri3 << endl;
            //f3(int());
            //f3(static_cast<const int&&>(42));
        }
        {
            //const int &&rrci1 = i;
            //const int &&rrci2 = ci;
            const int &&rrci3 = int();
            f3((rrci3+0));
            const int &&rrci4 = 42;
            //rrci4 = 32;
            //f3(rrci3);
        }
    }
    {
        int i = 8;
        int &&rri = moving(i);
        ++rri;
        cout << "i = " << i << endl;
        int &&rrci = moving(42);
    }
    {
        string s1("hi"), s2;
        s2 = moving(string("bye"));
        cout << "s1 = " << s1 << endl;
        cout << "s2 = " << s2 << endl;
        s2 = moving(s1);
        cout << "s1 = " << s1 << endl;
        cout << "s2 = " << s2 << endl;
    }
    {
        int j = 2;
        flip1(f, j, 42);
        cout << "j = " << j << endl;
        flip2(f, j, 42);
        cout << "j = " << j << endl;
    }
    {
        int j = 2;
        flip2(g, j, 42);
        cout << "j = " << j << endl;
    }
    {
        int j;
        int i = static_cast<int&&>(j);
    }
    {
        string s("hi");
        //const string *sp = &s;
        cout << debug_rep(s) << endl;
    }
    {
        cout << debug_rep("hi world") << endl;
    }
    {
        cout << "====== test exercise ======" << endl;
        int i = 42, *p = &i;
        const int ci = 0, *p2 = &ci;
        gg(42);
        gg(p);
        gg(ci);
        gg(p2);
        ff(42);
        ff(p);
        ff(ci);
        ff(p2);
    }
    {
        int i = 0; double d = 3.14; string s = "how now brown cow";
        foo(i, s, 42, d);
        foo(s, 42, "hi");
        foo(d, s);
        foo("hi");
    }
    {
        int i = 156; double d = 3.14; string s = "how now brown cow";
        cout << "(1)--" << endl << endl << endl;
        print(cout, d, 1);
        cout << "(2)--" << endl << endl << endl;
        print(cout, s, d);
        cout << "(3)--" << endl << endl << endl;
        print(cout, i, s, 42, s);
        cout << "(13)--" << endl << endl << endl;
        print(cout, i, d, s, 42, d, i, s,s,s,s,s,s,s, 42);

    }
    {
        string expected = "1928";
        string actual = "1365";
        if (expected != actual)
            error_msg({"functionX", expected, actual});
        else
            error_msg({"functionX", "okay"});
    }
    {
        int i = 156; double d = 3.14; string s = "how now brown cow";
        errorMsg(cout, i, d, s, 42, d);
    }
    return 0;
}
shared_ptr
