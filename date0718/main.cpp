#include <iostream>
#include <cstdlib>

using namespace std;

void *operator new(size_t size)
{
    cout << "call func @@ void *operator new(size_t size) @@" << endl;
    if (void *p = malloc(size))
        return p;
    else
        throw bad_alloc();
}

void operator delete(void *p) noexcept
{
    cout << "call func @@ void operator delete(void *p) noexcept @@" << endl;
    free(p);
}

int main()
{
    cout << "Hello world!" << endl;
    string *sp = new string("a value");
    *sp = "hdfkla; ";
    cout << *sp << endl;
    string s("abcdedd");
    cout << string(s, 0, 2) << endl;
    delete sp;
    {
        void *vp = operator new(sizeof(string));
        string *sp = new(vp) string("abcv");
        cout << *sp << endl;
        sp->~string();
        sp = new(vp) string("xyz");
        cout << *sp << endl;
        sp->~string();
        operator delete(vp);
    }
    return 0;
}
