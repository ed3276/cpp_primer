#include <iostream>
#include <regex>
#include <fstream>
#include <set>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
    //regex r("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    //regex r("[^c]ei");
    smatch results;
    string filename;
    if (cin >> filename) {
        if (regex_search(filename, results, r)) {
            cout << "\"" << results.str(1) << "\"" << " is invalid word." << endl;
        }
        else
            cout << "spelling correct!" << endl;
    }
    {
        try {
            regex r("*?[[:alnum:]]+[b-a]\\.(cpp|cxx|cc)$", regex::icase);
        }catch (regex_error e)
        {
            cout << e.what() << "\ncode: " << e.code() << endl;
        }
    }
    {
        regex r("([[:alnum:]]+)\\.(cpp|cxx|cc)$", regex::icase);
        //neighbor
        cmatch results;
        if (regex_search("myfile.cc", results, r))
            cout << results.str(1) << endl;
    }
    //file = "receipt
    {
        set<string> except{"albeit", "neighbor"};
        string file, s;
        ifstream infile("main.cpp");
        while (getline(infile, s))
            file += s + '\n';
        cout << file << endl << endl;
        //albeit
        string pattern("[^c]ei");
        pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
        regex r(pattern, regex::icase);
        //file = "receipt freind theif receive";
        for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it) {
            //if (except.find(it->str()) != except.end()) continue;
            auto pos = it->prefix().length();
            pos = pos > 40 ? pos - 40 : 0;
            cout << it->prefix().str().substr(pos)
                << "\n\t\t>>> " << it->str() << " <<<\n"
                << it->suffix().str().substr(0, 40)
                << endl;
            //cout << it->str() << endl;
        }
    }
    return 0;
}
