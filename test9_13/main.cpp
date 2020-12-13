#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    std::list<int> lst{1,2,5};
    std::vector<int> lst2={4,9,0};
    std::vector<double> v1(lst.begin(),lst.end());
    std::vector<double> v2(lst2.cbegin(),lst2.cend());
    std::vector<double> v3;
    v3.assign(lst.begin(),lst.end());
    std::list<const char*> lst3{"Hi","HELLO"};
    std::vector<string> v5;
    v5.assign(lst3.begin(),lst3.end());
    std::cout << lst2.max_size() << std::endl;
    lst2.emplace_back(99);
    lst2.push_back(199);
    std::list<int> iList;
    for(size_t ix=0;ix!=4;++ix)
        iList.push_front(ix);
    for(std::list<int>::const_iterator it=iList.cbegin();it!=iList.end();++it)
        std::cout << *it << " ";
    std::string s("KILL is!");
    //s.clear();
    s[100];
    s.at(100);
    if(!s.empty()){
    std::cout << (s.back()='S') <<std::endl;
    std::cout << (s.front()='#') << std::endl;
    std::cout <<s<<std::endl;
    }
    return 0;
}
