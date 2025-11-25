#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll rst = 1;

ll fnc(ll n)
{
    if (n == 0)
    {
        return 0;
    }
    rst *= n;
    return fnc(n - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll n;
    cin >> n;
    fnc(n);
    cout << rst << '\n';

    return 0;
}