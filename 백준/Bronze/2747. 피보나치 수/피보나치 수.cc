#include <iostream>
using namespace std;
using ll = long long;
int fib[50];
int n;

void solve()
{
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= 45; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
    cin >> n;
    cout << fib[n] << '\n';

    return 0;
}