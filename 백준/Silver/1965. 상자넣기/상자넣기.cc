#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int ary[1001];
int dp[1001];
int n;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ary[i];
        dp[i] = 1;
    }
}

void rstfnc()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (ary[j] < ary[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout << *max_element(dp + 1, dp + n + 1) << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    rstfnc();

    return 0;
}