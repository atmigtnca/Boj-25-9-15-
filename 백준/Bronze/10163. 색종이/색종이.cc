#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y, s, h;
    cin >> n;
    vector<int> col(n + 1, 0);
    vector<int> cek(1001 * 1001, 0);

    for (size_t i = 1; i <= n; ++i)
    {
        cin >> x >> y >> s >> h;
        for (size_t a = y; a < y + h; ++a)
        {
            for (size_t b = x; b < x + s; ++b)
            {
                int k = cek[(1001 * a) + b];
                if (k != i && i != 1)
                {
                    --col[k];
                }
                ++col[i];
                cek[(1001 * a) + b] = i;
            }
        }
    }

    for (size_t i = 1; i <= n; i++)
    {
        cout << col[i] << '\n';
    }

    return 0;
}