#include <iostream>
#include <string>

using namespace std;

void reset(int *ip)
{
    *ip = 0;
    ip = 0;
}

void reset(int &i)
{
    i = 0;
}

bool isShorter (const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() < s2.size() ? s1 : s2;
}

string &shorterString(string &s1, const string &s2)
{
    const string &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
    return const_cast<string &>(r);
}

string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();
    occurs = 0;
    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if(s[i] == c){
            if(ret == s.size())
                ret = i;
            ++occurs;
        }
    }
    return ret;
}

int main()
{
    cout << "Hello world!" << endl;
    int i = 42;
    reset(&i);
    cout << i << endl;
    i = 42;
    reset(i);
    cout << i << endl;
    string s1("fafdk kjfdkalf");
    string s2{"adfd"};
    cout << isShorter(s1, s2) << endl;
    decltype (s1.size()) occurs = 0;
    const string &s = "hello string";
    decltype(s1.size()) ret = find_char("hello world", 'f', occurs);
    cout << " f occurs " << occurs << " times, the first position is " << ret << " ." << endl;
    {
        const int ci = 42;
        int i = ci;
        int * const p = &i;
        *p = 0;
        //p = p;
    }
    {
        using Record = int;
        using Phone = double;
        Record lookup(Phone);
        Record lookup(Phone);
        Record lookup(Phone);
        Record lookup(const Phone);
        Record lookup(Phone*);
        Record lookup(Phone* const);
    }

    {
        const string s1("123"), s2("123456");
        string s3("123"), s4("123456");
        shorterString(s1, s2) = "111";
        cout << shorterString(s1, s2) << endl;
        shorterString(s3, s4) = "zzz";
        cout << s3 << endl;
    }
    return 0;
}
