#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
#define Y first
#define X second
int grp[26][26];
bool vis[26][26];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    string ipt;
    for (int i = 0; i < n; i++)
    {
        cin >> ipt;
        for (int j = 0; j < n; j++)
        {
            grp[i][j] = ipt[j] - '0';
        }
    }

    int cut = 0;
    vector<int> rst;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grp[i][j] && !vis[i][j])
            {
                int v = 0;
                cut++;
                queue<pair<int, int>> cur;
                cur.push({i, j});
                v++;
                vis[i][j] = true;
                while (!cur.empty())
                {
                    auto [cy, cx] = cur.front();
                    cur.pop();
                    for (size_t a = 0; a < 4; a++)
                    {
                        int ny = cy + dy[a];
                        int nx = cx + dx[a];
                        if (vis[ny][nx])
                        {
                            continue;
                        }
                        if (grp[ny][nx] != 1)
                        {
                            continue;
                        }
                        cur.push({ny, nx});
                        v++;
                        vis[ny][nx] = true;
                    }
                }
                rst.push_back(v);
            }
        }
    }

    cout << cut << '\n';
    sort(rst.begin(), rst.end());
    for (auto mem : rst)
    {
        cout << mem << '\n';
    }

    return 0;
}