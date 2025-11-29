#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;
int vis[301][301];
int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

void fnc()
{
    int siz, srow, scol, trow, tcol;
    queue<pair<int, int>> cur;
    memset(vis, -1, sizeof(vis));

    cin >> siz;
    cin >> srow >> scol;
    cin >> trow >> tcol;

    if (srow == trow && scol == tcol)
    {
        cout << 0 << '\n';
        return;
    }

    cur.push({srow, scol});
    vis[srow][scol] = 0;

    while (!cur.empty())
    {
        auto [ny, nx] = cur.front();
        cur.pop();

        for (size_t i = 0; i < 8; i++)
        {
            int cy = ny + dy[i];
            int cx = nx + dx[i];
            if (cy < 0 || cy >= siz || cx < 0 || cx >= siz)
            {
                continue;
            }
            if (vis[cy][cx] != -1)
            {
                continue;
            }
            cur.push({cy, cx});
            vis[cy][cx] = vis[ny][nx] + 1;
            if (cy == trow && cx == tcol)
            {
                cout << vis[cy][cx] << '\n';
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int c;
    cin >> c;

    while (c--)
    {
        fnc();
    }

    return 0;
}