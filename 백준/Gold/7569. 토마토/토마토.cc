#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int mota[101][101][101];
bool vis[101][101][101];
int dx[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

struct xyz
{
    int z;
    int y;
    int x;
};
queue<xyz> cur;

int day, viv;
int m, n, h;

void bfs()
{
    while (!cur.empty())
    {
        size_t sz = cur.size();
        day++;

        for (size_t j = 0; j < sz; j++)
        {
            auto [cz, cy, cx] = cur.front();
            cur.pop();
            for (int i = 0; i < 6; i++)
            {
                int nz = cz + dz[i];
                int ny = cy + dy[i];
                int nx = cx + dx[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >= h)
                {
                    continue;
                }
                if (mota[nz][ny][nx] == 1 || mota[nz][ny][nx] == -1)
                {
                    continue;
                }
                mota[nz][ny][nx] = 1;
                vis[nz][ny][nx] = true;
                cur.push({nz, ny, nx});
                viv++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> m >> n >> h;

    int MAX = m * n * h;
    for (int z = 0; z < h; z++)
    {
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < m; x++)
            {
                cin >> mota[z][y][x];
                if (mota[z][y][x] == -1)
                {
                    MAX--;
                }
                else if (mota[z][y][x] == 1)
                {
                    cur.push({z, y, x});
                    viv++;
                }
            }
        }
    }

    bfs();
    if (viv == MAX)
    {
        cout << day - 1 << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}