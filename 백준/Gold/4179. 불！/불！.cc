#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
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

    int row, col;
    cin >> row >> col;

    vector<vector<int>> vist(row, vector<int>(col, -1));  // 불난시간
    vector<vector<int>> time(row, vector<int>(col, -1));  // 탈출하는시간

    queue<pair<int, int>> fire;  // 불난위치
    queue<pair<int, int>> esc;   // 지훈이의 위치

    vector<string> ipt(row);
    for (size_t i = 0; i < row; i++)
    {
        cin >> ipt[i];
        for (size_t j = 0; j < col; j++)
        {
            char tmp = ipt[i][j];
            if (tmp == 'J')  // 지훈이 위치 표시
            {
                esc.push({i, j});
                time[i][j] = 0;
            }
            else if (tmp == 'F')  // 불난위치표시
            {
                fire.push({i, j});
                vist[i][j] = 0;
            }
        }
    }

    while (!fire.empty())  // 불이 난 시간 체크
    {
        auto spt = fire.front();
        fire.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int ny = spt.Y + dy[i], nx = spt.X + dx[i];
            if (ny < 0 || ny >= row || nx < 0 || nx >= col)
            {
                continue;
            }
            if (ipt[ny][nx] == '#' || vist[ny][nx] != -1)
            {
                continue;
            }
            vist[ny][nx] = vist[spt.Y][spt.X] + 1;
            fire.push({ny, nx});
        }
    }

    int rst;
    while (!esc.empty())
    {
        auto spt = esc.front();
        esc.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = spt.Y + dy[i], nx = spt.X + dx[i];
            if (ny < 0 || ny >= row || nx < 0 || nx >= col)
            {
                rst = time[spt.Y][spt.X] + 1;
                cout << rst << '\n';
                return 0;
            }

            if ((vist[ny][nx] > time[spt.Y][spt.X] + 1 || vist[ny][nx] == -1) &&
                (time[ny][nx] == -1 && ipt[ny][nx] != '#'))
            {
                time[ny][nx] = time[spt.Y][spt.X] + 1;
                esc.push({ny, nx});
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';

    return 0;
}