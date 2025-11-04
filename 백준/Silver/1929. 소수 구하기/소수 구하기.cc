#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> m >> n;

    vector<bool> sou(n + 1);
    for (size_t i = 2; i <= n; i++)
    {
        sou[i] = true;
    }
    sou[1] = false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (!sou[i])
        {
            continue;
        }
        for (size_t j = 2; i * j <= n; j++)
        {
            sou[i * j] = false;
        }
    }

    for (size_t i = m; i <= n; i++)
    {
        if (sou[i])
        {
            cout << i << '\n';
        }
    }

    return 0;
}