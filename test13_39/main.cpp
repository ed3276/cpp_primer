#include <iostream>
#include <memory>

class StrVec
{
public:
    StrVec() : _capacity(0), elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(const StrVec& sv);
    explicit StrVec(const std::string& s);
    StrVec(std::size_t n, const std::string& s);
    StrVec& operator=(const StrVec&);
    ~StrVec() { free(); }
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return _capacity; }
    std::string* begin() const { return elements; }
    std::string* end() const { return first_free; }
    const std::string* cbegin() const { return elements; }
    const std::string* cend() const { return first_free; }
    std::string* push_back(const std::string& s) { chk_n_alloc(); alloc.construct(first_free++,s); return first_free-1;}
    std::string* pop_back() { if(first_free!=elements) alloc.destroy(--first_free); return first_free;}

private:
    std::size_t _capacity;
    std::string* elements;
    std::string* first_free;
    std::string* cap;
    static std::allocator<std::string> alloc;
    static std::size_t init_capacity;
    std::string* alloc_n_copy(const std::string* b, const std::string* e, std::string* p);
    void free() { if(elements){while(first_free!=elements) alloc.destroy(--first_free); alloc.deallocate(elements,_capacity); }}
    void chk_n_alloc() { if(first_free==cap) reallocate();}
    std::string* reallocate();
    std::size_t init_cap();
};
std::allocator<std::string> StrVec::alloc;
std::size_t StrVec::init_capacity = 32;
std::size_t StrVec::init_cap() { return init_capacity; }
StrVec::StrVec(const StrVec& sv) \
    : _capacity(sv._capacity),elements(alloc.allocate(_capacity)), first_free(elements+sv.size()), cap(elements+_capacity)
{
    uninitialized_copy_n(sv.elements,sv.size(),elements);
}

//拷贝赋值操作符中含有拷贝构造函数和析构函数的操作
StrVec& StrVec::operator=(const StrVec& sv)
{
    StrVec tmp(sv);
    free();
    _capacity = tmp._capacity;
    elements = alloc.allocate(_capacity);
    first_free = elements + tmp.size();
    cap = elements + _capacity;
    uninitialized_copy_n(tmp.elements,tmp.size(),elements);
    return *this;
}

StrVec::StrVec(const std::string& s) \
: _capacity(init_cap()),elements(alloc.allocate(_capacity)), first_free(elements), cap(elements+_capacity)
{
    alloc.construct(first_free++, s);
}

StrVec::StrVec(std::size_t n, const std::string& s) \
: _capacity(init_cap()), elements(alloc.allocate(_capacity)), first_free(elements), cap(elements+_capacity)
{
    while(n-- > 0){
        chk_n_alloc();
        alloc.construct(first_free++, s);
    }
}

std::string* StrVec::alloc_n_copy(const std::string* const b, const std::string* const e, std::string* p)
{
    while(e > b + _capacity) p = reallocate();
    uninitialized_copy(b, e , p);
    return p;
}

std::string* StrVec::reallocate()
{
    std::size_t c1 = first_free - elements;
    if(_capacity == 0)
    {
        _capacity = init_cap();
    }
    else
    {
        _capacity = _capacity * 2;
    }
    std::string *t = alloc.allocate(_capacity);
    alloc_n_copy(elements, first_free, t);
    free();
    elements = t;
    first_free = elements + c1;
    cap = elements + _capacity;
    return elements;
}
int main()
{
    std::cout << "Hello world!" << std::endl;
    StrVec s;
    StrVec sv1(1,"hello");
    sv1.push_back("world");
    std::cout << "begin to print" << std::endl;
    for(std::string* it=sv1.begin();it!=sv1.end();++it)
        std::cout << *it << std::endl;
    std::cout << sv1.size() << std::endl;
    std::cout << sv1.capacity() << std::endl;

    StrVec sv2;
    std::cout << "begin to print" << std::endl;
    for(std::string* it=sv2.begin();it!=sv2.end();++it)
        std::cout << *it << std::endl;
    std::cout << sv2.size() << std::endl;
    std::cout << sv2.capacity() << std::endl;

    sv1.pop_back();
    sv2 = sv1;
    std::cout << "begin to print" << std::endl;
    for(std::string* it=sv2.begin();it!=sv2.end();++it)
        std::cout << *it << std::endl;
    std::cout << sv2.size() << std::endl;
    std::cout << sv2.capacity() << std::endl;

    return 0;
}
