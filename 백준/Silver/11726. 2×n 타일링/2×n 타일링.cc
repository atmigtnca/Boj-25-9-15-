#include <iostream>
using namespace std;
using ll = long long;
ll ary[1001];
int N;

ll moD(ll input) { return input % 10007; }

int twoN(int n)
{
    ary[1] = 1, ary[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        ary[i] = moD(moD(ary[i - 1]) + moD(ary[i - 2]));
    }
    return ary[n];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    cout << twoN(N) << '\n';

    return 0;
}