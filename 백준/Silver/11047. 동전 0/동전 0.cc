#include <iostream>
using namespace std;
using ll = long long;
int mut[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, k, rst = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> mut[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (mut[i] > k)
        {
            continue;
        }

        rst += k / mut[i];
        k %= mut[i];

        if (k == 0)
        {
            break;
        }
    }

    cout << rst << '\n';

    return 0;
}