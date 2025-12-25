#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;

    cin >> N >> M;

    if (M == 1 && N == 1)
    {
        cout << 0 << '\n';
    }
    else if (M == 1)
    {
        cout << N - 1 << '\n';
    }
    else if (N == 1)
    {
        cout << M - 1 << '\n';
    }
    else
    {
        cout << (N - 1) + ((M - 1) * N) << '\n';
    }

    return 0;
}