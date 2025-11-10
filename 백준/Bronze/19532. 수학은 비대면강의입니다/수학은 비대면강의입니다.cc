#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int chk = 0;
    for (int y = -999; y < 1000; y++)
    {
        for (int x = -999; x < 1000; x++)
        {
            int n1 = (a * x) + (b * y);
            int n2 = (d * x) + (e * y);
            if (c == n1 && f == n2)
            {
                cout << x << ' ' << y << '\n';
                return 0;
            }
        }
    }

    return 0;
}
