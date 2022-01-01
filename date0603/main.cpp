#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <string>
using namespace std;

class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr) : os(s) { }
    template <typename T> void operator()(T *p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

template <typename T> class Blob {
public:
    template <typename It> Blob(It b, It e);
};

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) {
    cout << "initial Blob Object..." << endl;
}

int main()
{
    cout << "Hello world!" << endl;
    double *p = new double;
    DebugDelete d;
    d(p);
    int *ip = new int;
    DebugDelete()(ip);
    unique_ptr<int, DebugDelete> up(new int, DebugDelete());
    unique_ptr<string, DebugDelete> sp(new string, DebugDelete());
    {

        int ia[] = {0,1,2,3,4,5,6,7,8,9};
        vector<long> vi = {0,1,2,3,4,5,6,7,8,9};
        list<const char*> w = {"now", "is", "the", "time"};
        Blob<int> a1(begin(ia), end(ia));
        Blob<int> a2(vi.begin(), vi.end());
        Blob<string> a3(w.begin(), w.end());
    }
    return 0;
}
