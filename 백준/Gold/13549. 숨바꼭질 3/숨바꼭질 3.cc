#include <deque>
#include <iostream>
// #include <utility>
#include <vector>
using namespace std;
using ll = long long;
vector<int> vis;
deque<int> cur;
int N, K;

int hideNseek()
{
    while (!cur.empty())
    {
        int spt = cur.front();
        cur.pop_front();

        int nzt[3] = {spt * 2, spt - 1, spt + 1};

        for (int i = 0; i < 3; i++)
        {
            int next = nzt[i];

            if (next < 0 || next > 100000)
            {
                continue;
            }
            if (vis[next] > -1)
            {
                continue;
            }

            if (i == 0)
            {
                vis[next] = vis[spt];
            }
            else
            {
                vis[next] = vis[spt] + 1;
            }

            if (next == K)
            {
                return vis[next];
            }

            if (i == 0)
            {
                cur.push_front(next);
            }
            else
            {
                cur.push_back(next);
            }
        }
    }
    return 0;
}

void input()
{
    cin >> N >> K;
    vis.resize(100001, -1);
    cur.push_back(N);
    vis[N] = 0;

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    cout << hideNseek() << '\n';

    return 0;
}