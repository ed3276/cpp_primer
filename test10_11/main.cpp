#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
void elimDups(vector<string> &words);
auto isShorter(const string &s1, const string &s2) -> bool;

int main()
{
    cout << "Hello world!" << endl;
    vector<string> words = {"the", "quick", "red", "fox", "jumps", "over", "the", "slow", "red", "turtle"};
    elimDups(words);
    //sort(words.begin(),words.end());
    stable_sort(words.begin(),words.end(),isShorter);

    for(auto i:words)
        std::cout << i << " ";
    cout << endl;
    return 0;
}


void elimDups(vector<string> &words)
{
    sort(words.begin(),words.end());
    vector<string>::iterator it = unique(words.begin(),words.end());
    words.erase(it,words.end());
}

auto isShorter(const string &s1, const string &s2) -> bool
{
    return s1.size() < s2.size();
}
