#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ll cur = 1, rst = 0;
    ll s;
    cin >> s;

    while (1)
    {
        rst = cur * (cur + 1);
        if (rst / 2 > s)
        {
            break;
        }
        cur++;
    }

    cout << cur - 1 << '\n';

    return 0;
}