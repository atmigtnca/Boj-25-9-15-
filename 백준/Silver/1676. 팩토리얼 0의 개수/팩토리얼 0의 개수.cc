#include <iostream>
using namespace std;
using ll = long long;
int cnt = 0;
int N;

void solve(int n)
{
    int num = n;
    while (1)
    {
        int chk = num % 5;
        if (!chk)
        {
            num /= 5;
            cnt++;
        }
        else
        {
            return;
        }
    }
}

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        solve(i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    cout << cnt << '\n';

    return 0;
}