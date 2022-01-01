#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    {
        bitset<33> bitvec(0xFF);
        bitvec.to_string('N', 'U');
        cout << bitvec << endl;
    }
    return 0;
}
