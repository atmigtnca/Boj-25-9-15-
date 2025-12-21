#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#define Y first
#define X second
using namespace std;
using ll = long long;
queue<pair<int, int>> cur;
pair<int, int> srt, edn;
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int wtr[51][51];  // 홍수 발생
int hdh[51][51];  // 고슴도치 이동
int R, C;

void escfnc()  // 고슴도치 탈출 함수
{
    cur.push(srt);
    while (!cur.empty())
    {
        auto [cy, cx] = cur.front();
        cur.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if (ny == edn.Y && nx == edn.X)
            {
                cout << hdh[cy][cx] + 1 << '\n';
                return;
            }

            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
            {
                continue;
            }
            if (wtr[ny][nx] <= 0 || hdh[ny][nx] > 0)
            {
                continue;
            }
            if (hdh[cy][cx] + 1 >= wtr[ny][nx])
            {
                continue;
            }

            cur.push({ny, nx});
            hdh[ny][nx] = hdh[cy][cx] + 1;
        }
    }

    cout << "KAKTUS\n";
    return;
}

void wtrfnc()  // 홍수발생 함수
{
    while (!cur.empty())
    {
        size_t sze = cur.size();
        while (sze--)
        {
            auto [cy, cx] = cur.front();
            cur.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                {
                    continue;
                }
                if ((wtr[ny][nx] != 1e9 && wtr[ny][nx] >= 0) ||
                    wtr[ny][nx] == -1)
                {
                    continue;
                }

                cur.push({ny, nx});
                wtr[ny][nx] = wtr[cy][cx] + 1;
            }
        }
    }

    return;
}

void iptfnc()  // 입력받는 함수
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        fill(wtr[i], wtr[i] + C, 1e9);
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            char ipt;
            cin >> ipt;
            switch (ipt)
            {
                case 'X':
                    wtr[i][j] = -1;
                    continue;
                case '*':
                    cur.push({i, j});
                    wtr[i][j] = 0;
                    continue;
                case 'S':
                    srt = {i, j};
                    continue;
                case 'D':
                    edn = {i, j};
                    wtr[i][j] = -1;
                    continue;
            }
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    iptfnc();  // 입력받는
    wtrfnc();  // 홍수발생
    escfnc();  // 고슴도치 탈출

    return 0;
}