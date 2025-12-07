#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
vector<vector<int>> frd;
int vis[101];
int N, M;

int cntfnc(int a)
{
    queue<int> cur;
    fill(vis, vis + N + 1, -1);
    cur.push(a);
    vis[a] = 0;
    while (!cur.empty())
    {
        int spt = cur.front();
        cur.pop();
        for (auto mem : frd[spt])
        {
            if (vis[mem] != -1)
            {
                continue;
            }
            cur.push(mem);
            vis[mem] = vis[spt] + 1;
        }
    }
    int add = 0;
    for (int i = 1; i <= N; i++)
    {
        add += vis[i];
    }
    return add;
}

void addfnc()
{
    cin >> N >> M;
    frd.resize(N + 1);

    while (M--)
    {
        int a, b;
        cin >> a >> b;
        frd[a].push_back(b);
        frd[b].push_back(a);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int MIN = 505050, rstIdx;

    addfnc();

    for (int i = 1; i <= N; i++)
    {
        int tmp = cntfnc(i);
        if (tmp < MIN)
        {
            MIN = tmp;
            rstIdx = i;
        }
    }

    cout << rstIdx << '\n';

    return 0;
}