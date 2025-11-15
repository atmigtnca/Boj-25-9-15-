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

    bool endchk = true;
    int count = 0, rst;
    while (endchk)
    {
        // count++;
        pair<int, int> cur = p.front();
        p.pop();

        if (cur.Y == n && cur.X == m)
        {
            rst = mro[cur.Y][cur.X];
            break;
        }
        // auto [cur_y, cur_x] = p.front();
        int tmp = mro[cur.Y][cur.X];

        // for (size_t a = 1; a <= n; a++)
        // {
        //     for (size_t i = 1; i <= m; i++)
        //     {
        //         cout << mro[a][i] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.Y + dy[i], nx = cur.X + dx[i];
            if (ny < 0 || ny > n || nx < 0 || nx > m)
            {
                continue;
            }
            if (mro[ny][nx] == 1 && vis[ny][nx] != true)
            {
                mro[ny][nx] = tmp + 1;
                p.push({ny, nx});
            }
            // if (ny == n && nx == m)
            // {
            //     rst = mro[ny][nx];
            //     endchk = false;
            // }
        }
        vis[cur.Y][cur.X] = true;

        // for (size_t a = 1; a <= n; a++)
        // {
        //     for (size_t i = 1; i <= m; i++)
        //     {
        //         cout << mro[a][i] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
    }

    cout << rst << '\n';

    return 0;
}