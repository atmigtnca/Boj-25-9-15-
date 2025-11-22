#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
int N, M, rst = 0;
bool vis[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    cin >> M;

    vector<vector<int>> grp(N + 1);
    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        grp[s].push_back(e);
        grp[e].push_back(s);
    }

    queue<int> cur;
    cur.push(1);
    vis[1] = true;
    while (!cur.empty())
    {
        int spt = cur.front();
        cur.pop();
        for (auto mem : grp[spt])
        {
            if (vis[mem])
            {
                continue;
            }
            rst++;
            cur.push(mem);
            vis[mem] = true;
        }
    }

    cout << rst << '\n';

    return 0;
}