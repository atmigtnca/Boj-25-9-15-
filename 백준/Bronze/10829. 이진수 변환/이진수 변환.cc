#include <iostream>
using namespace std;
using ll = long long;

void fnc(ll n)
{
    ll di = n / 2;  // 몫
    ll mo = n % 2;  // 나머지

    if (n == 1)
    {
        cout << mo;
        return;
    }
    fnc(di);
    cout << mo;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll n;
    cin >> n;

    fnc(n);
    cout << '\n';

    return 0;
}