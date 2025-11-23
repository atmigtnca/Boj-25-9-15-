#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
int n, m, rst;
vector<vector<int>> grp;
vector<bool> vis;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    cin >> m;

    grp.resize(n + 1);
    vis.resize(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }

    queue<int> mf;
    for (auto mem : grp[1])
    {
        mf.push(mem);
        rst++;
        vis[mem] = true;
    }

    vis[1] = true;
    while (!mf.empty())
    {
        int spt = mf.front();
        mf.pop();
        for (auto mem : grp[spt])
        {
            if (vis[mem])
            {
                continue;
            }
            vis[mem] = true;
            rst++;
        }
    }

    cout << rst << '\n';

    return 0;
}