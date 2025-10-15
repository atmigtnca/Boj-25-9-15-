#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, b;
    string c;
    cin >> n;

    vector<pair<int, string>> age;

    for (size_t i = 0; i < n; i++)
    {
        cin >> b >> c;
        age.push_back({b, c});
    }

    stable_sort(age.begin(), age.end(), [](const auto &a, const auto &b)
                { return a.first < b.first; });

    for (auto &member : age)
    {
        cout << member.first << ' ' << member.second << '\n';
    }

    return 0;
}