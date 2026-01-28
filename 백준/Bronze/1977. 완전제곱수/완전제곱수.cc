#include <iostream>
using namespace std;
using ll = long long;
int ary[101];
int n, m;

void solve()
{
    for (int i = 1; i <= 100; i++)
    {
        ary[i] = i * i;
    }

    int mIn = 1e9;
    int rst = 0;
    for (int i = 1; i <= 100; i++)
    {
        if (m <= ary[i] && ary[i] <= n)
        {
            rst += ary[i];
            mIn = mIn > ary[i] ? ary[i] : mIn;
        }
    }
    if (!rst)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << rst << '\n';
        cout << mIn << '\n';
    }
}

void input() { cin >> m >> n; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();

    return 0;
}