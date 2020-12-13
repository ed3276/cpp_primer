#include <iostream>
#include <string>
using namespace std;

string add2str(const string &s1, const string &s2);
string multiply(string num1, string num2);

int main()
{
    cout << "Hello world!" << endl;
    cout << add2str("500000000000","110000000000") << endl;
    cout << add2str("456","1995") << endl;
    cout << multiply("4986379436526147432469958204718329158211863797453691789509292244161982290580525007195048267692",
"2044896994719") << endl;
    return 0;
}

string add2str(const string &s1, const string &s2)
{
    string ans;
    int m1 = 0, m2 = 0, c = 0;
    string::const_reverse_iterator ri1=s1.crbegin();
    string::const_reverse_iterator ri2=s2.crbegin();
    while(ri1!=s1.crend() && ri2!=s2.crend())
    {
        m1 = *ri1 - '0';
        m2 = *ri2 - '0';
        ans += ((m1 + m2 + c)%10 + '0');
        c = (m1 + m2 + c) / 10;
        ++ri1;++ri2;
    }
    while(ri1!=s1.crend())
    {
        m1 = *ri1 - '0';
        ans += ((m1 + c)%10 + '0');
        c = (m1 + c) / 10;
        ++ri1;
    }
    while(ri2!=s2.crend())
    {
        m2 = *ri2 - '0';
        ans += ((m2 + c)%10 + '0');
        c = (m2 + c) / 10;
        ++ri2;
    }
    if(c) ans += (c + '0');
    return string(ans.crbegin(),ans.crend());
}
string multiply_core(const string &a, const string &b, int a_idx, int b_idx)
{
    string ret;
    if(a.size()==0||b.size()==0) return string(1, '0');
    if(a.size()==1 && b.size()==1)
    {
        ret = string(a_idx+b_idx,'0');
        int m1 = a[0] - '0', m2 = b[0] - '0', tmp = m1*m2;
        if(tmp)
        {
            ret += ((tmp%10) + '0');
            if(tmp>9)
                ret += (m1*m2/10 + '0');
            return string(ret.crbegin(),ret.crend());
        }
        else
            return string(1, '0');
    }
    string a1(a.cbegin(),a.cbegin()+(a.cend()-a.cbegin())/2);
    string a2(a.cbegin()+(a.cend()-a.cbegin())/2,a.cend());
    string b1(b.cbegin(),b.cbegin()+(b.cend()-b.cbegin())/2);
    string b2(b.cbegin()+(b.cend()-b.cbegin())/2,b.cend());
    string s1 = multiply_core(a1,b1,a_idx+a.size()-(a.cend()-a.cbegin())/2,b_idx+b.size()-(b.cend()-b.cbegin())/2);
    string s2 = multiply_core(a2,b2,a_idx,b_idx);
    string s3 = multiply_core(a1,b2,a_idx+a.size()-(a.cend()-a.cbegin())/2,b_idx);
    string s4 = multiply_core(a2,b1,a_idx,b_idx+b.size()-(b.cend()-b.cbegin())/2);
    ret = add2str(ret,s1);
    ret = add2str(ret,s2);
    ret = add2str(ret,s3);
    ret = add2str(ret,s4);
    return ret;
}

string multiply(string num1, string num2)
{
    string ans;
    ans = multiply_core(num1, num2, 0, 0);
    return ans;
}
