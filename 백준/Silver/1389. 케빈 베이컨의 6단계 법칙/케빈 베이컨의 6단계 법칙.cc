#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
vector<vector<int>> frd;
int vis[101];
int rst[101];
int N, M;

int minfnc()
{
    int MIN = *min_element(rst + 1, rst + N + 1);
    for (int i = 1; i <= N; i++)
    {
        if (rst[i] == MIN)
        {
            return i;
        }
    }
}

void cntfnc(int a)
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
    for (int i = 1; i <= N; i++)
    {
        rst[a] += vis[i];
    }
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

    addfnc();

    for (int i = 1; i <= N; i++)
    {
        cntfnc(i);
    }

    cout << minfnc() << '\n';

    return 0;
}