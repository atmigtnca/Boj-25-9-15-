#include <array>
#include <iostream>
using namespace std;
const int MAX = 15;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int fc;
    cin >> fc;

    array<array<int, MAX>, MAX> hus = {};

    for (size_t i = 0; i < 15; i++)
    {
        hus[0][i] = i;
    }

    for (size_t K = 1; K < MAX; K++)
    {
        for (size_t N = 1; N < MAX; N++)
        {
            hus[K][N] = hus[K][N - 1] + hus[K - 1][N];
        }
    }

    int k, n;
    for (size_t i = 0; i < fc; i++)
    {
        cin >> k >> n;
        cout << hus[k][n] << '\n';
    }

    return 0;
}