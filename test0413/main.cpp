#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include "..\\include\\common.h"
#include <iterator>
#include <fstream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    vector<int> ivec{1, 3, 4, 5, 5, 5, 98, 493, 3, 31, 3, 9};
    sort(ivec.begin(), ivec.end());
    PRINTC(ivec);
    list<int> ilst;
    unique_copy(ivec.begin(), ivec.end(), inserter(ilst, ilst.begin()));
    PRINTC(ilst);
    {
        /*
        istream_iterator<int> int_in(cin);
        istream_iterator<int> eof_in;
        ifstream infile("afile");
        istream_iterator<string> str_it(infile);
        vector<int> ivec;
        while(int_in != eof_in)
            ivec.push_back(*int_in++);
        PRINTC(ivec);
        */
    }
    {
        istream_iterator<double> in_iter(cin), in_eof;
        vector<double> ivec(in_iter, in_eof);
        PRINTC(ivec);
        ostream_iterator<double> out_iter(cout, " # ");
        for (auto e : ivec)
            *out_iter++ = e;
        cout << endl;
        copy(ivec.begin(), ivec.end(), out_iter);
        cout << endl;
        for (vector<double>::const_reverse_iterator it = ivec.crbegin(); it != ivec.crend(); ++it)
            out_iter = *it;
    }
    {

    }
    return 0;
}
