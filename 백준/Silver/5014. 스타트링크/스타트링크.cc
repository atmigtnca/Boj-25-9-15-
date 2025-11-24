#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int f, s, g, u, d;
int vis[1000001];
int dx[2];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> f >> s >> g >> u >> d;
    if (s == g)
    {
        cout << 0 << '\n';
        return 0;
    }

    dx[0] = u, dx[1] = -d;
    fill(vis, vis + f + 1, -1);

    // f : 건물 높이
    // s : 현재 높이
    // g : 타겟 높이
    // u : u만큼 위로
    // d : d만큼 아래로

    queue<int> cur;
    cur.push(s);
    vis[s] = 0;
    while (!cur.empty())
    {
        int spt = cur.front();
        cur.pop();
        for (int i = 0; i < 2; i++)
        {
            int nx = spt + dx[i];
            if (nx < 1 || nx > f)
            {
                continue;
            }
            if (vis[nx] != -1)
            {
                continue;
            }
            cur.push(nx);
            vis[nx] = vis[spt] + 1;
            if (nx == g)
            {
                cout << vis[nx] << '\n';
                return 0;
            }
        }
    }
    cout << "use the stairs\n";

    return 0;
}