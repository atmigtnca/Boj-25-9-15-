#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
vector<vector<int>> fml;
vector<int> vis;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, t1, t2, m;
    cin >> n;
    cin >> t1 >> t2;
    cin >> m;

    fml.resize(n + 1);
    vis.resize(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int e, s;
        cin >> e >> s;
        fml[e].push_back(s);
        fml[s].push_back(e);
    }

    queue<int> cur;
    cur.push(t1);
    while (!cur.empty())
    {
        int spt = cur.front();
        cur.pop();
        // cout << spt << ' ' << vis[spt] << '\n';

        for (auto mem : fml[spt])
        {
            if (mem == t2)
            {
                cout << vis[spt] + 2 << '\n';
                return 0;
            }
            if (vis[mem] != -1)
            {
                continue;
            }
            cur.push(mem);
            vis[mem] = vis[spt] + 1;
        }
    }

    cout << -1 << '\n';

    return 0;
}