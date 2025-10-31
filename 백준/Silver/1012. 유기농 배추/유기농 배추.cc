#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

array<int, 4> dx = {-1, 1, 0, 0};
array<int, 4> dy = {0, 0, 1, -1};

void earthworm(vector<vector<int>>& cBg, int x, int y)
{
    cBg[y][x] = 0;

    queue<pair<int, int>> one;
    one.push({y, x});

    while (!one.empty())
    {
        auto [ysch, xsch] = one.front();
        one.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int tmp = cBg[ysch + dy[i]][xsch + dx[i]];
            int ty = ysch + dy[i], tx = xsch + dx[i];
            if (tmp == 1)
            {
                one.push({ty, tx});
                cBg[ty][tx] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ts;
    cin >> ts;

    for (size_t i = 0; i < ts; i++)
    {
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> cbg(n + 2, vector<int>(m + 2, 0));
        for (size_t j = 0; j < k; j++)
        {
            int x, y;
            cin >> x >> y;
            cbg[y + 1][x + 1] = 1;
        }
        int cut = 0;
        for (size_t y = 1; y < n + 1; y++)
        {
            for (size_t x = 1; x < m + 1; x++)
            {
                if (cbg[y][x] == 1)
                {
                    earthworm(cbg, x, y);
                    cut++;
                }
            }
        }
        cout << cut << '\n';
    }

    return 0;
}