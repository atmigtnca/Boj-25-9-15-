#include <iostream>
using namespace std;
using ll = long long;
int fib[44][4];
int n;

void fibfnc()
{
    fib[0][0] = 1, fib[0][1] = 0;
    fib[1][0] = 0, fib[1][1] = 1;

    for (int i = 2; i <= 40; i++)
    {
        fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
        fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
    }
}

void rstfnc()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int ipT;
        cin >> ipT;
        cout << fib[ipT][0] << ' ' << fib[ipT][1] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fibfnc();
    rstfnc();

    return 0;
}