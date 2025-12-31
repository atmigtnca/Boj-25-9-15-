#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> input;
int fib[44][4];
int n, max_ipt = 0;

void rstout()
{
    for (int i = 0; i < n; i++)
    {
        int idx = input[i];
        cout << fib[idx][0] << ' ' << fib[idx][1] << '\n';
    }
}

void fibfnc()
{
    fib[0][0] = 1, fib[0][1] = 0;
    fib[1][0] = 0, fib[1][1] = 1;

    for (int i = 2; i <= max_ipt; i++)
    {
        fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
        fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
    }
}

void ipt()
{
    cin >> n;
    input.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
        max_ipt = max(input[i], max_ipt);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    ipt();
    fibfnc();
    rstout();

    return 0;
}