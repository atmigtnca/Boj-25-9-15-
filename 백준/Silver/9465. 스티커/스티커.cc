#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int ipt[2][100000];
int dp[2][100000];
int n, m;

void dpsolve()
{
    dp[0][0] = ipt[0][0];
    dp[1][0] = ipt[1][0];
    dp[0][1] = ipt[0][1] + dp[1][0];
    dp[1][1] = ipt[1][1] + dp[0][0];
    for (int i = 2; i < m; i++)
    {
        dp[0][i] = ipt[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
        dp[1][i] = ipt[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
    }
    cout << max(dp[0][m - 1], dp[1][m - 1]) << '\n';
}

void input()
{
    cin >> n;
    while (n--)
    {
        cin >> m;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> ipt[i][j];
            }
        }
        dpsolve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();

    return 0;
}