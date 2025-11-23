#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<vector<int>> grp;
vector<vector<int>> rst;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    grp.resize(n + 1);
    rst.resize(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ip;
            cin >> ip;
            if (ip)
            {
                grp[i].push_back(j);
            }
        }
    }

    stack<int> cur;
    for (int i = 1; i <= n; i++)
    {
        for (auto mem : grp[i])
        {
            cur.push(mem);
        }
        while (!cur.empty())
        {
            int spt = cur.top();
            cur.pop();
            if (rst[i][spt])
            {
                continue;
            }
            rst[i][spt] = 1;
            for (auto mem : grp[spt])
            {
                cur.push(mem);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << rst[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}