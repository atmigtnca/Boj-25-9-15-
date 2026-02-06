#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> ary;
int n, m;

void solve()
{
    int scur = 0, ecur = 0;
    ll rst = 2e9;
    while (1)
    {
        if (ecur == n || scur == n)
        {
            break;
        }

        ll mus = ary[ecur] - ary[scur];
        if (mus >= m)
        {
            rst = min(rst, mus);
            scur++;
        }
        else
        {
            ecur++;
        }
        // cout << ary[scur] << ' ' << ary[ecur] << '\n';
        // cout << scur << ' ' << ecur << '\n';
    }
    cout << rst << '\n';
}

void input()
{
    cin >> n >> m;
    ary.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ary[i];
    }
    sort(ary.begin(), ary.end());
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();

    return 0;
}