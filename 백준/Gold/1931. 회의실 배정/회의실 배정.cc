#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
vector<pair<int, int>> ary;
int n, rst = 1;

bool chk(const pair<int, int> a, const pair<int, int> b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

void solve()
{
    sort(ary.begin(), ary.end(), chk);

    int v = ary[0].second;
    for (int i = 1; i < n; i++)
    {
        if (ary[i].first >= v)
        {
            v = ary[i].second;
            rst++;
        }
    }
}

void input()
{
    cin >> n;
    ary.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ary[i].first >> ary[i].second;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
    cout << rst << '\n';

    return 0;
}