#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;
    ll nk = n - k, rstu = 1, rstd = 1, rst;

    for (size_t i = k + 1; i <= n; i++)
    {
        rstu *= i;
    }

    for (size_t i = 1; i <= nk; i++)
    {
        rstd *= i;
    }

    cout << rstu / rstd << '\n';

    return 0;
}