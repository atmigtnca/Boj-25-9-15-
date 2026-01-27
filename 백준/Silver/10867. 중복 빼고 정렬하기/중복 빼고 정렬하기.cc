#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> ary;
int n;

void solve()
{
    sort(ary.begin(), ary.end());
    ary.erase(unique(ary.begin(), ary.end()), ary.end());
}

void input()
{
    cin >> n;
    ary.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ary[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
    for (int mem : ary)
    {
        cout << mem << ' ';
    }
    cout << '\n';

    return 0;
}