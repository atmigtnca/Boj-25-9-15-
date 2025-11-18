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
    int melt;  // 녹는 깊이
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int row, col;
    cin >> row >> col;

    vector<vector<int>> hig(row, vector<int>(col, 0));  // 빙산의 높이
    vector<vector<int>> vis(row, vector<int>(col, 0));  // 빙산의 유무
    queue<pair<int, int>> eit;                          // 빙산
    queue<ice> hol;

    // 일단 지금 생각했을때
    // 기존의 BFS로 하면 동시에 바다에 닿는 면적은 계산할 수 없음
    // 동시에 바다에 닿는다고 생각해야됨!

    // 그러면 BFS를 돌면서 우선 녹는 깊이를 저장해놓고
    // 그 후에 한번에 녹는걸로 하면 될거같음!

    int count = 0;  // 빙산 개수 체크
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            cin >> hig[i][j];
            if (hig[i][j] > 0)
            {
                count++;           // 빙산 개수 체크
                vis[i][j] = 1;     // 빙산 유무 체크
                eit.push({i, j});  // 빙산 위치 저장
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
                if (hig[ny][nx] == 0)  // 0을 만나면
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

        // for (size_t i = 0; i < row; i++)
        // {
        //     for (size_t j = 0; j < col; j++)
        //     {
        //         cout << hig[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << count << '\n';

        vector<vector<int>> chk(row, vector<int>(col, 0));
        queue<pair<int, int>> cek;
        int endcheck = 1;  // 새로운 빙하에 갈때마다 개수를 증가해서
                           // endcheck == count면 아직 빙하가 한조각인거임
        if (cunt != count)
        {
            cek.push(eit.front());
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
                // cout << endcheck << "===" << '\n';
                cout << rst << '\n';
                return 0;
            }
        }
    }
    cout << 0 << '\n';

    return 0;
}

// for (size_t i = 0; i < row; i++)
// {
//     for (size_t j = 0; j < col; j++)
//     {
//         cout << hig[i][j] << ' ';
//     }
//     cout << '\n';
// }
// cout << count << '\n';