#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<ll> cnt;
ll n, m, rst = 0;

void solve()
{
    for (auto mem : cnt)
    {
        if (!mem)
        {
            continue;
        }
        rst += (mem * (mem - 1)) / 2;
    }
}

void input()
{
    cin >> n >> m;
    cnt.resize(m);

    ll sum = 0;

    for (int i = 1; i <= n; i++)
    {
        ll ipt;
        cin >> ipt;
        sum = (sum + ipt % m) % m;
        if (!sum)
        {
            rst++;
        }
        cnt[sum]++;
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