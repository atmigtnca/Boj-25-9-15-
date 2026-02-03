#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a, b, c, d;

    cin >> a >> b >> c >> d;
    int sht = a + b;
    int wlk = c;

    if (sht <= d && wlk <= d)
    {
        cout << "~.~\n";
    }
    else if (sht > d && wlk > d)
    {
        cout << "T.T\n";
    }
    else if (sht <= d)
    {
        cout << "Shuttle\n";
    }
    else
    {
        cout << "Walk\n";
    }

    return 0;
}