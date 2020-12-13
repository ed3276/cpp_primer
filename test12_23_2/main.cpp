#include <iostream>
#include <memory>

int main()
{
    std::cout << "Hello world!" << std::endl;
    std::allocator<std::string> alloc;
    std::string *p = alloc.allocate(10);
    std::string *q = p;
    alloc.construct(q++,"hello");
    alloc.construct(q++,10,'c');
    alloc.construct(q++,"hi");
    for(std::string *m=p;m!=q;++m)
        std::cout << *m << std::endl;
    while(q!=p)
        alloc.destroy(--q);
    alloc.deallocate(p,10);
    return 0;
}
