#include <iostream>
using namespace std;
using ll = long long;
bool used1[40];
bool used2[40];
bool used3[40];
int cnt = 0;
int n;

void fnc(int cur)
{
    if (cur == n)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (used1[i] || used2[i + cur] || used3[cur - i + n - 1])
        {
            continue;
        }
        used1[i] = 1;
        used2[i + cur] = 1;
        used3[cur - i + n - 1] = 1;
        fnc(cur + 1);
        used1[i] = 0;
        used2[i + cur] = 0;
        used3[cur - i + n - 1] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    fnc(0);
    cout << cnt;

    return 0;
}