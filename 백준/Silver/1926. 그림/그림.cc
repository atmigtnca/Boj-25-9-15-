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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> img(n, vector<int>(m));

    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cin >> img[y][x];
        }
    }

    int mAx = 0, count = 0;
    for (size_t a = 0; a < n; a++)
    {
        for (size_t b = 0; b < m; b++)
        {
            if (img[a][b])
            {
                int tmp = 1;
                queue<pair<int, int>> lst;
                img[a][b] = 0;
                lst.push({a, b});

                while (!lst.empty())
                {
                    for (size_t i = 0; i < 4; i++)
                    {
                        int nx = lst.front().X + dx[i],
                            ny = lst.front().Y + dy[i];
                        if (nx >= 0 && ny >= 0 && nx < m && ny < n)
                        {
                            if (img[ny][nx])
                            {
                                // for (int y = 0; y < n; y++)
                                // {
                                //     for (int x = 0; x < m; x++)
                                //     {
                                //         cout << img[y][x] << ' ';
                                //     }
                                //     cout << '\n';
                                // }
                                // cout << '\n';
                                img[ny][nx] = 0;
                                tmp++;
                                lst.push({ny, nx});
                            }
                        }
                    }
                    lst.pop();
                }
                mAx = max(mAx, tmp);
                count++;
            }
        }
    }

    cout << count << '\n' << mAx << '\n';

    // for (int y = 0; y < n; y++)
    // {
    //     for (int x = 0; x < m; x++)
    //     {
    //         cout << img[y][x] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}