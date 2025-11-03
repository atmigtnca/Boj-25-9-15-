#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> star = {"     /~\\",    "    ( oo|",      "    _\\=/_",
                           "   /  _  \\",  "  //|/.\\|\\\\", " ||  \\ /  ||",
                           "============", "|          |",   "|          |",
                           "|          |"};

    for (auto& call : star)
    {
        cout << call << '\n';
    }

    return 0;
}