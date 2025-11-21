#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
using ll = long long;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char wrd[101][101];
int vis[101][101];
int N;

int rgfn(int mode)
{
    fill(&vis[0][0], &vis[N - 1][N], 0);
    int rst = 0;
    queue<pair<int, int>> cur;
    for (size_t row = 0; row < N; row++)
    {
        for (size_t col = 0; col < N; col++)
        {
            if (!vis[row][col])
            {
                rst++;
                cur.push({row, col});
                vis[row][col] = true;
                while (!cur.empty())
                {
                    auto [cy, cx] = cur.front();
                    cur.pop();
                    char mid = wrd[cy][cx];

                    for (size_t i = 0; i < 4; i++)
                    {
                        int nx = cx + dx[i];
                        int ny = cy + dy[i];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                        {
                            continue;
                        }
                        if (vis[ny][nx])
                        {
                            continue;
                        }

                        if (mid == 'B')
                        {
                            if (wrd[ny][nx] == 'B')
                            {
                                cur.push({ny, nx});
                                vis[ny][nx] = 1;
                            }
                        }
                        else if (mode == 1)  // 적록색약 유
                        {
                            if (wrd[ny][nx] == 'G' || wrd[ny][nx] == 'R')
                            {
                                cur.push({ny, nx});
                                vis[ny][nx] = 1;
                            }
                        }
                        else if (mode == 0)  // 적록색약 무
                        {
                            if (mid == 'R')
                            {
                                if (wrd[ny][nx] == 'R')
                                {
                                    cur.push({ny, nx});
                                    vis[ny][nx] = 1;
                                }
                            }
                            else if (mid == 'G')
                            {
                                if (wrd[ny][nx] == 'G')
                                {
                                    cur.push({ny, nx});
                                    vis[ny][nx] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return rst;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    string ipt;
    for (size_t i = 0; i < N; i++)
    {
        cin >> ipt;
        for (size_t j = 0; j < N; j++)
        {
            wrd[i][j] = ipt[j];
        }
    }

    cout << rgfn(0) << ' ' << rgfn(1) << '\n';

    return 0;
}