#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int ipt[1010][5];
int rgb[1010][5];
int n;

void dp()
{
    rgb[1][1] = ipt[1][1], rgb[1][2] = ipt[1][2], rgb[1][3] = ipt[1][3];

    for (int i = 2; i <= n; i++)
    {
        rgb[i][1] = min(rgb[i - 1][2], rgb[i - 1][3]) + ipt[i][1];
        rgb[i][2] = min(rgb[i - 1][1], rgb[i - 1][3]) + ipt[i][2];
        rgb[i][3] = min(rgb[i - 1][1], rgb[i - 1][2]) + ipt[i][3];
    }
}

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ipt[i][1] >> ipt[i][2] >> ipt[i][3];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    dp();
    cout << min(rgb[n][1], min(rgb[n][2], rgb[n][3])) << '\n';

    return 0;
}