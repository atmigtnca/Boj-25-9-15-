#include <iostream>
using namespace std;
using ll = long long;
int dp[12];
int n;

void fnc()
{
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (int i = 4; i < 11; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fnc();
    cin >> n;
    while (n--)
    {
        int ipt;
        cin >> ipt;
        cout << dp[ipt] << '\n';
    }

    return 0;
}