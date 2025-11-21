#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
int N, M, V;
bool vis[1001];

void bfs(vector<vector<int>>& wrd)
{
    queue<int> cur;
    cur.push(V);
    vis[V] = true;
    cout << V << ' ';
    while (!cur.empty())
    {
        int spt = cur.front();
        cur.pop();
        for (auto mem : wrd[spt])
        {
            if (vis[mem])
            {
                continue;
            }
            cur.push(mem);
            vis[mem] = true;
            cout << mem << ' ';
        }
    }
}

void dfs(vector<vector<int>>& wrd, int cur)
{
    vis[cur] = true;
    cout << cur << ' ';
    for (auto mem : wrd[cur])
    {
        if (vis[mem])
        {
            continue;
        }
        dfs(wrd, mem);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> V;

    vector<vector<int>> wrd(N + 1);
    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        wrd[s].push_back(e);
        wrd[e].push_back(s);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(wrd[i].begin(), wrd[i].end());
    }

    dfs(wrd, V);
    cout << '\n';
    fill(vis, vis + N+1, false);
    bfs(wrd);

    return 0;
}