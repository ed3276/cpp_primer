#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isLargeThan5Char(const std::string &s);
auto isShorter(const std::string &s1,const std::string &s2) -> bool;
void biggies(std::vector<std::string> &words,std::vector<std::string>::size_type sz);
int main()
{
    std::cout << "Hello world!" << std::endl;
    //std::vector<std::string> words = {"I like siwmming.", "ue", "zhangxiuli", "panda", "zz", "cat", "tiger"};
    /*std::vector<std::string>::iterator it = partition(words.begin(),words.end(),isLargeThan5Char);
    for(std::vector<std::string>::iterator ib = words.begin(); ib!=it; ++ib)
        std::cout << *ib << std::endl;
    std::cout << std::endl;*/
    std::vector<std::string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    biggies(words,4);
    return 0;
}

bool isLargeThan5Char(const std::string &s)
{
    return s.size()>=5;
}

void biggies(std::vector<std::string> &words,std::vector<std::string>::size_type sz)
{
    std::sort(words.begin(),words.end());
    std::vector<std::string>::iterator it = unique(words.begin(),words.end());
    words.erase(it, words.end());
    stable_sort(words.begin(),words.end(),isShorter);
    for_each(words.begin(),words.end(),[](const std::string &s){std::cout << s << " ";});
    std::cout << std::endl;
    //auto f = [sz](const std::string &s) {return s.size() >= sz;};
    auto its = find_if(words.begin(),words.end(),[sz](const std::string &s) {return s.size() >= sz;});
    for(std::vector<std::string>::iterator ib = its; ib!=words.end(); ++ib)
        std::cout << *ib << std::endl;
    std::cout << std::endl;
}

auto isShorter(const std::string &s1,const std::string &s2) -> bool
{
    return s1.size() < s2.size();
}
