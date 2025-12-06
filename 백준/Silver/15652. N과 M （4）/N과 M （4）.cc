#include <iostream>
using namespace std;
using ll = long long;
int n, m;
int arr[10];

void fnc(int k, int q)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = q; i <= n; i++)
    {
        arr[k] = i;
        fnc(k + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    fnc(0, 1);

    return 0;
}