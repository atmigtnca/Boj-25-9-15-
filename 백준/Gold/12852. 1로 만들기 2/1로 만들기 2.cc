#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> dp, tme;

void rstfnc(int N)
{
    int cur = N;
    cout << cur << ' ';
    while (cur != 1)
    {
        cur = tme[cur];
        cout << cur << ' ';
    }
    cout << '\n';
}

int fnc(int N)
{
    dp.resize(N + 1);
    tme.resize(N + 1);

    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        tme[i] = i - 1;
        if (i % 2 == 0)
        {
            if (dp[i] > dp[i / 2] + 1)
            {
                dp[i] = dp[i / 2] + 1;
                tme[i] = i / 2;
            }
        }
        if (i % 3 == 0)
        {
            if (dp[i] > dp[i / 3] + 1)
            {
                dp[i] = dp[i / 3] + 1;
                tme[i] = i / 3;
            }
        }
    }
    return dp[N];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    cout << fnc(n) << '\n';
    rstfnc(n);

    return 0;
}