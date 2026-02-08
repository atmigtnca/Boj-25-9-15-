#include <iostream>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;
queue<pair<int, int>> cur;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int ary[5][5];
int vis[5][5];

int solve()
{
    while (!cur.empty())
    {
        auto [cy, cx] = cur.front();
        cur.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
            {
                continue;
            }
            if (ary[ny][nx] == 1)
            {
                return vis[cy][cx];
            }
            if (ary[ny][nx] == -1 || vis[ny][nx] > 0)
            {
                continue;
            }
            cur.push({ny, nx});
            vis[ny][nx] = vis[cy][cx] + 1;
        }
    }
    return -1;
}

void input()
{
    int srty, srtx;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> ary[i][j];
        }
    }
    cin >> srty >> srtx;
    cur.push({srty, srtx});
    vis[srty][srtx] = 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    cout << solve() << '\n';

    return 0;
}