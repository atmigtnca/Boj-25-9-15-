#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int dis[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(dis, dis + 100001, -1);

    queue<int> cur;
    cur.push(n);
    dis[n] = 0;

    while (!cur.empty())
    {
        int mem = cur.front();
        cur.pop();

        if (mem == k)
        {
            cout << dis[mem] << '\n';
            return 0;
        }

        int next[3] = {mem - 1, mem + 1, mem * 2};

        for (auto nxt : next)
        {
            if (0 > nxt || nxt > 100000 || dis[nxt] != -1)
            {
                continue;
            }
            dis[nxt] = dis[mem] + 1;
            cur.push(nxt);
        }
    }

    return 0;
}