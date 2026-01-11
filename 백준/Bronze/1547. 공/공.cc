#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int ary[5] = {0, 1};
    int m;

    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        int tmp = ary[x];
        ary[x] = ary[y];
        ary[y] = tmp;
    }

    for (int i = 1; i <= 3; i++)
    {
        if (ary[i])
        {
            cout << i << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';

    return 0;
}