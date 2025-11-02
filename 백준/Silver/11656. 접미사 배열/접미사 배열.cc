#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string dix;
    cin >> dix;
    const int size = dix.size();
    vector<string> typ;
    typ.reserve(size);

    for (size_t i = 0; i < size; i++)
    {
        typ.push_back(dix.substr(i));
    }

    sort(typ.begin(), typ.end());

    for (auto& mem : typ)
    {
        cout << mem << '\n';
    }

    return 0;
}