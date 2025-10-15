#include <iostream>
using namespace std;
typedef long long ll;

ll kob(ll a, ll b, ll c)
{
    if (b == 1)
    {
        return a % c;
    }
    ll rst = kob(a, (b / 2), c);
    rst = (rst * rst) % c;
    if (b % 2)
    {
        rst = (rst * a) % c;
    }
    return rst;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    cout << kob(a, b, c) << '\n';

    return 0;
}