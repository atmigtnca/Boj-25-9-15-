#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
queue<pair<int, int>> cur;
bool vis[1001][1001];
int dis[1001][1001];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int n, m;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> dis[i][j];
            if (dis[i][j] == 2)
            {
                cur.push({i, j});
                dis[i][j] = 0;
                vis[i][j] = true;
            }
        }
    }
}

void solve()
{
    while (!cur.empty())
    {
        auto [cy, cx] = cur.front();
        cur.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            {
                continue;
            }
            if (dis[ny][nx] == 0 || vis[ny][nx] == true)
            {
                continue;
            }

            cur.push({ny, nx});
            dis[ny][nx] = dis[cy][cx] + 1;
            vis[ny][nx] = true;
        }
    }
}

void mnus() {}

void output()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dis[i][j] == 1 && vis[i][j] == false)
            {
                cout << -1 << ' ';
                continue;
            }
            cout << dis[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
    output();

    return 0;
}