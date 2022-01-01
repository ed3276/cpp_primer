#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    {
        cout << "Hello world!" << endl;
        cout << true << " " << false << endl;
        cout << boolalpha << true << " " << false << endl;
        bool b;
        cout << boolalpha << b << noboolalpha << endl;
        cout << true << endl;
    }

    {
        cout << showbase << uppercase;
        cout << "default: " << 20 << " " << 1024 << endl;
        cout << "octal: " << oct << 20 << " " << 1024 << endl;
        cout << "hex: " << hex << 20 << " " << 1024 << endl;
        cout << "dec: " << dec << 20 << " " << 1024 << endl;
        cout << noshowbase << nouppercase;
    }
    {
        cout << "precision: " << cout.precision() << ", value: " << sqrt(2.0) << endl;
        cout << cout.precision(12);
        cout << "precision: " << cout.precision() << ", value: " << sqrt(2.0) << endl;
        cout << setprecision(6);
    }
    {
        cout << 2.0 << endl;
        cout << showpoint << showpos << hexfloat;
        cout << 2.0 << endl;
    }
    {
        cout << "default format: " << 100 * sqrt(2.0) << '\n'
            << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
            << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
            << "hexadecimal: " << hexfloat << 100 * sqrt(2.0) << '\n'
            << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << "\n\n";
    }
    {
        int i = -16;
        double d = 3.14159;
        cout << "i: " << setw(12) << i << "next col" << '\n';
        cout << "d: " << setw(12) << d << "next col" << '\n';
        cout << left
            << "i: " << setw(12) << i << "next col" << '\n'
            << "d: " << setw(12) << d << "next col" << '\n'
            << right;
        cout << right
            << "i: " << setw(12) << i << "next col" << '\n'
            << "d: " << setw(12) << d << "next col" << '\n';
        cout << internal
            << "i: " << setw(12) << i << "next col" << '\n'
            << "d: " << setw(12) << d << "next col" << '\n';
        cout << setfill('#')
            << "i: " << setw(12) << i << "next col" << '\n'
            << "d: " << setw(12) << d << "next col" << '\n'
            << setfill(' ');
    }
    {
        cin >> noskipws;
        char ch;
        while (cin >> ch)
            cout << ch;
        cin >> skipws;
    }
    {
        char ch;
        while (cin.get(ch))
            cout.put(ch);
    }
    cin.clear();
    {
        char ch;
        cin.get(ch);
        cout.put(ch);
    }
    cin.clear();
    {
        int ch;
        while ((ch = cin.get()) != EOF) {
            cout << "peek: ";
            //cin.unget();
            cin.putback(ch);
            cout.put(cin.peek());
            if (cin.peek() == 'q') break;
            cout.put(cin.get());
            cout.put(ch);
        }
    }
    {
        cin.clear();
        constexpr size_t N = 10;
        char ch[N+1] = {0};
        cin.get(ch, N, '*');
        cout << string(ch) << endl;
        cout.put(cin.peek());
    }
    {
        cin.clear();
        constexpr size_t N = 10;
        char ch[N+1] = {0};
        cin.getline(ch, N, '*');
        cout << string(ch) << endl;
        cout.put(cin.peek());
    }
    {
        cin.clear();
        constexpr size_t N = 10;
        char ch[N+1] = {0};
        cin.ignore(6, '$');
        cin.read(ch, N);
        cout << string(ch) << endl;
        //cout.put(cin.peek());
        {
            cout << cin.gcount() << endl;
        }
        {
            cout.write(ch, string(ch).length()/2) << endl;
        }
    }

    return 0;
}
