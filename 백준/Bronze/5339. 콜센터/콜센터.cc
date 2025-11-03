#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<string> star;
    star.reserve(10);

    star.push_back("     /~\\");
    star.push_back("    ( oo|");
    star.push_back("    _\\=/_");
    star.push_back("   /  _  \\");
    star.push_back("  //|/.\\|\\\\");
    star.push_back(" ||  \\ /  ||");
    star.push_back("============");
    star.push_back("|          |");
    star.push_back("|          |");
    star.push_back("|          |");

    for (auto& call : star)
    {
        cout << call << '\n';
    }

    return 0;
}