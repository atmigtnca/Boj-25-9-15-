#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
vector<vector<int>> grp;
vector<int> dis;
queue<int> cur;
int max_num = 0;
int N, M;

void disfnc()  // 거리찾는함수
{
    int max_cnt = 0;

    cur.push(1);
    dis[1] = 0;
    while (!cur.empty())
    {
        int nzt = cur.front();
        cur.pop();
        for (auto mem : grp[nzt])
        {
            if (dis[mem] != -1)
            {
                continue;
            }
            cur.push(mem);
            dis[mem] = dis[nzt] + 1;
            if (dis[mem] > max_cnt)
            {
                max_cnt = dis[mem];
            }
        }
    }

    bool chk = true;
    int rst1, rst2 = max_cnt, rst3 = 0;

    for (int i = 1; i <= N; i++)
    {
        if (dis[i] == max_cnt)
        {
            if (chk)
            {
                rst1 = i;
                chk = false;
            }
            rst3++;
        }
    }

    cout << rst1 << ' ' << rst2 << ' ' << rst3 << '\n';
    return;
}

void iptfnc()  // 입력받는함수
{
    cin >> N >> M;
    grp.resize(N + 1);
    dis.resize(N + 1, -1);

    while (M--)
    {
        int ai, bi;
        cin >> ai >> bi;
        grp[ai].push_back(bi);
        grp[bi].push_back(ai);
    }

    disfnc();
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    iptfnc();

    return 0;
}