#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> xy(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> xy[i].first >> xy[i].second;
    }

    sort(xy.begin(), xy.end(), [](const auto &a, const auto &b)
         {
             if (a.second == b.second)
             {
                 return a.first < b.first;
             }
             else
             {
                 return a.second < b.second;
             } });

    for (const auto &mem : xy)
    {
        cout << mem.first << ' ' << mem.second << '\n';
    }

    return 0;
}