#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
vector<vector<vector<int>>> vis;
vector<vector<int>> dis;
int n, m;

struct sta
{
    int x;
    int y;
    int brk;
};
queue<sta> cur;

void output()
{
    int rstNBrk = vis[0][n - 1][m - 1];
    int rstBrk = vis[1][n - 1][m - 1];
    int rst = (rstBrk == -1 || rstNBrk == -1) ? max(rstBrk, rstNBrk)
                                              : min(rstBrk, rstNBrk);

    cout << rst << '\n';
}

void solve()
{
    cur.push({0, 0, 0});
    vis[0][0][0] = 1;
    vis[1][0][0] = 1;

    while (!cur.empty())
    {
        auto [cy, cx, brk] = cur.front();
        cur.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            int nbrk = brk;
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            {
                continue;
            }
            if ((dis[ny][nx] == 1 && nbrk == 1) || vis[nbrk][ny][nx] != -1)
            {
                continue;
            }
            else if (dis[ny][nx] == 1 && nbrk == 0)
            {
                nbrk = 1;
            }
            cur.push({ny, nx, nbrk});
            vis[nbrk][ny][nx] = vis[brk][cy][cx] + 1;
        }
    }
}

void input()
{
    char ipt;
    cin >> n >> m;
    dis.resize(n, vector<int>(m));
    vis.resize(2, vector<vector<int>>(n, vector<int>(m, -1)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ipt;
            dis[i][j] = ipt - '0';
        }
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