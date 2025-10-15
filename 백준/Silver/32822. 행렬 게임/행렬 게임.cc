#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long m;
    cin >> n >> m;

    vector<vector<int>> hoon(n, vector<int>(n, 0));
    vector<int> rsd(n + 1, -1);

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            cin >> hoon[i][j];
        }
    }

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            int chn;
            cin >> chn;
            int b = hoon[i][j] - chn;
            hoon[i][j] = (b > 0 ? b : -b);
        }
    }

    long long rst = 0;
    for (size_t i = 0; i < m; ++i)
    {
        int M, max = 0;
        cin >> M;
        if (rsd[M] != -1)
        {
            rst += rsd[M];
        }
        else
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (hoon[j][M - 1] > max)
                {
                    max = hoon[j][M - 1];
                }
            }
            rsd[M] = max;
            rst += max;
        }
    }

    cout << rst << "\n";

    return 0;
}