#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define Y first
#define X second
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

struct ice
{
    int y;
    int x;
    int melt;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int row, col;
    cin >> row >> col;

    vector<vector<int>> hig(row, vector<int>(col, 0));
    vector<vector<int>> vis(row, vector<int>(col, 0));
    vector<vector<int>> chk(row, vector<int>(col, 0));
    queue<pair<int, int>> cek;
    queue<pair<int, int>> eit;
    queue<ice> hol;

    int count = 0;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> hig[i][j];
            if (hig[i][j] > 0)
            {
                count++;
                vis[i][j] = 1;
                eit.push({i, j});
            }
        }
    }

    int rst = 0;
    while (!eit.empty())
    {
        rst++;
        int cunt = eit.size();
        for (size_t i = 0; i < cunt; i++)
        {
            auto cur = eit.front();
            eit.pop();
            int down = 0;
            for (size_t i = 0; i < 4; i++)
            {
                int ny = cur.Y + dy[i];
                int nx = cur.X + dx[i];
                if (hig[ny][nx] == 0)
                {
                    down++;
                }
            }
            hol.push({cur.Y, cur.X, down});
        }

        while (!hol.empty())
        {
            auto spt = hol.front();
            hol.pop();
            hig[spt.y][spt.x] -= spt.melt;
            if (hig[spt.y][spt.x] <= 0)
            {
                hig[spt.y][spt.x] = 0;
                vis[spt.y][spt.x] = 0;
                count--;
            }
            if (vis[spt.y][spt.x] != 0)
            {
                eit.push({spt.y, spt.x});
            }
        }

        if (count == 0)
        {
            break;
        }

        int endcheck = 1;

        if (cunt != count)
        {
            cek.push(eit.front());
            for (size_t i = 0; i < row; i++)
            {
                fill(chk[i].begin(), chk[i].end(), 0);
            }
            chk[cek.front().Y][cek.front().X] = 1;
            while (!cek.empty())
            {
                auto cur = cek.front();
                cek.pop();
                for (size_t i = 0; i < 4; i++)
                {
                    int ny = cur.Y + dy[i];
                    int nx = cur.X + dx[i];
                    if (chk[ny][nx] != 1 && vis[ny][nx] == 1)
                    {
                        cek.push({ny, nx});
                        chk[ny][nx] = 1;
                        endcheck++;
                    }
                }
            }
            if (endcheck != count)
            {
                cout << rst << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';

    return 0;
}