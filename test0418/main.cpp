#include <iostream>
#include <memory>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    int *pi = new int();
    long *pl = new long;
    char *pch = new char;
    char16_t *pch16 = new char16_t;
    //*pi = 42;
    cout << *pi ;
    double *pd = new double;
    float *pf = new float;
    string *ps = new string;
    cout << (*ps = "pdfd") << endl;
    auto p1 = new auto (*ps);
    cout << *p1;
    const int *pci = new const int (1024);
    delete pci;
    /*int *p11 = new int[10000000000];
    for (size_t i = 0; i != 10000000000; ++i)
        p11[i] = i;
    (void*)p11;*/
    //int *p2 = new (nothrow) int [1000000];
    {
        int i, *pi1 = &i, *pi2 = nullptr;
        double *pd = new double(33), *pd2 = pd;
        delete pd;
        //delete pd2;
    }
    {
        int *p(new int(42));
        int *p1{new int(42)};
    }
    {
        shared_ptr<double> p1(new double(42));
        shared_ptr<double> p2;
    }

    {
        unique_ptr<double> p1;
        unique_ptr<double> p2(new double (9.8));
//        unique_ptr<double> p3(p2);

        unique_ptr<double> p3(p2.release());
        cout << *p3 << endl;
    }
    {
        auto p = make_shared<int>(42);
        weak_ptr<int> q(p);
    }
    {
        int *pia = new int [100]();
        for (size_t i = 0; i != 100; ++i)
            pia[i] = i;
        ostream_iterator<int> os(cout, " $ ");
        copy(pia, pia + 100, os);
        delete pia;
        typedef int arrT[42];
        int *p = new arrT;
        delete [] p;
        int *pia3 = new int[10]{0,1,2,3,4,5,6,7,8,9};
        delete [] pia3;
        string *pis = new string[10] {"a", "an",string(19, 'c')};
        cout << pis[2] << endl;
        delete [] pis;
        auto sss = new string(10, 'x');
        delete sss;
        char *cp = new char[0];
        cout << endl << cp << endl;
        delete [] cp;
    }
    {
        unique_ptr<int[]> up(new int[100]);
        up.release();
        shared_ptr<int> sp(new int[10], [](int *p){delete [] p;});
        sp.reset();
    }
    {
        allocator<string> alloc;
        string * const p = alloc.allocate(10);
        auto q = p;
        alloc.construct(q++, 10, 'z');
        cout << *p << endl;
        while (p != q)
            alloc.destroy(--q);
        alloc.deallocate(p, 10);
    }
    {
        vector<double> v{0.1,.2,.3,.4,.5,.6,32.2,.9};
        allocator<double> alloc_d;
        double *p = alloc_d.allocate(10);
        uninitialized_copy(v.begin(), v.end(), p);
        for_each(p, p+10, [](double e){cout << e << " ";});
        alloc_d.deallocate(p, 10);
    }
    return 0;
}
