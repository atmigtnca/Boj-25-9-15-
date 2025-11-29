#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
int wrd[101][101];
bool vis[101][101];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};

void fil()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = y1; i < y2; i++)
    {
        fill(&wrd[i][x1], &wrd[i][x2], 1);
    }
}

void bfs(int m, int n)
{
    int allsize = 0;
    queue<pair<int, int>> cur;
    vector<int> siz;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!wrd[i][j] && !vis[i][j])
            {
                allsize++;
                int size = 1;
                cur.push({i, j});
                vis[i][j] = true;
                while (!cur.empty())
                {
                    auto [ny, nx] = cur.front();
                    cur.pop();
                    for (int k = 0; k < 4; k++)
                    {
                        int cy = ny + dy[k];
                        int cx = nx + dx[k];
                        if (cy < 0 || cy >= m || cx < 0 || cx >= n)
                        {
                            continue;
                        }
                        if (wrd[cy][cx] || vis[cy][cx])
                        {
                            continue;
                        }
                        size++;
                        cur.push({cy, cx});
                        vis[cy][cx] = true;
                    }
                }
                siz.push_back(size);
            }
        }
    }

    cout << allsize << '\n';
    sort(siz.begin(), siz.end());
    for (auto mem : siz)
    {
        cout << mem << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int m, n, k;
    cin >> m >> n >> k;

    while (k--)
    {
        fil();
    }

    bfs(m, n);

    return 0;
}