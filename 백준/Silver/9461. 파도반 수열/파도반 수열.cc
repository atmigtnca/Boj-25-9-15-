#include <iostream>
using namespace std;
using ll = long long;
ll dp[101] = {0, 1, 1, 1, 2};
int n;

void dpfnc()
{
    for (int i = 5; i <= 100; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 5];
    }
}

void iofnc()
{
    cin >> n;
    while (n--)
    {
        int ipt;
        cin >> ipt;
        cout << dp[ipt] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    dpfnc();
    iofnc();

    return 0;
}