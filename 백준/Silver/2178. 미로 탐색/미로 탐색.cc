#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
using ll = long long;
#define Y first
#define X second
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mro(n + 2, vector<int>(m + 2));
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, false));

    string ipt;
    for (size_t y = 1; y <= n; y++)
    {
        cin >> ipt;
        for (size_t x = 1; x <= m; x++)
        {
            mro[y][x] = ipt[x - 1] - '0';
        }
    }

    queue<pair<int, int>> p;
    p.push({1, 1});
    vis[1][1] = true;

    while (!p.empty())
    {
        pair<int, int> cur = p.front();
        p.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.Y + dy[i], nx = cur.X + dx[i];
            if (mro[ny][nx] == 1 && vis[ny][nx] != true)
            {
                mro[ny][nx] = mro[cur.Y][cur.X] + 1;
                p.push({ny, nx});
                vis[ny][nx] = true;
            }
        }
    }

    cout << mro[n][m] << '\n';

    return 0;
}