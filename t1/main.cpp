#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    vector<vector<int>> v1(8);
    vector<int> arr = {1,2,3};
    v1[0] = arr;
    for(auto e : v1[0])
        cout << e << " ";

    {
        int ival;
        cin >> ival;
        cout << "io stream state: " << ((cin.rdstate() & 0x01) |istream::goodbit) << endl;
        cout << "io stream state: " << cin.rdstate() << endl;
        cout << "io stream failbit state: " << istream::failbit << endl;
        if(cin.eof())
            cout << "i stream cin is eof" << endl;
        else
            cout << "i stream cin is not eof" << endl;
        if(cin.bad())
            cout << "i stream cin is badbit" << endl;
        else
            cout << "i stream cin is not badbit" << endl;
        if(cin.good())
            cout << "i stream cin is good" << endl;
        else
            cout << "i stream cin is not good" << endl;
        if(cin.fail())
            cout << "i stream cin is failbit || badbit" << endl;
        else
            cout << "i stream cin is not failbit and badbit" << endl;
        cin.clear();
        cout << "io stream state: " << cin.rdstate() << endl;
        if(cin.eof())
            cout << "i stream cin is eof" << endl;
        else
            cout << "i stream cin is not eof" << endl;
        if(cin.bad())
            cout << "i stream cin is badbit" << endl;
        else
            cout << "i stream cin is not badbit" << endl;
        if(cin.good())
            cout << "i stream cin is good" << endl;
        else
            cout << "i stream cin is not good" << endl;
        if(cin.fail())
            cout << "i stream cin is failbit || badbit" << endl;
        else
            cout << "i stream cin is not failbit and badbit" << endl;
        cout << unitbuf;
        cout << 9 << endl;
        cin >> ival;
        cout << 9 << endl;
        cin >> ival;
        cout << 9 << endl;
        cout << nounitbuf;
        cout << 8 << flush;
        cout << "hi" << ends;
        cout << 8 << endl;
    }
    return 0;
}
