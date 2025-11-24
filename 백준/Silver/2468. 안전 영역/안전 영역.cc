#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
using ll = long long;
int ele[101][101];
bool vis[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

queue<pair<int, int>> cur;
int bfs(int h)
{
    fill(&vis[0][0], &vis[n][n + 1], false);
    for (int i = 0; i < cur.size(); i++)
    {
        cur.pop();
    }
    int cut = 0;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            if (ele[y][x] > h && !vis[y][x])
            {
                cut++;
                cur.push({y, x});
                vis[y][x] = true;
                while (!cur.empty())
                {
                    auto [cy, cx] = cur.front();
                    cur.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        int ny = cy + dy[i];
                        int nx = cx + dx[i];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                        {
                            continue;
                        }
                        if (ele[ny][nx] <= h || vis[ny][nx])
                        {
                            continue;
                        }
                        cur.push({ny, nx});
                        vis[ny][nx] = true;
                    }
                }
            }
        }
    }
    return cut;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int MAX = 0, rst_MAX = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ele[i][j];
            MAX = max(MAX, ele[i][j]);
        }
    }

    for (int h = 1; h <= MAX; h++)
    {
        int a = bfs(h);
        rst_MAX = max(rst_MAX, a);
    }

    if (!rst_MAX)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << rst_MAX << '\n';
    }

    return 0;
}