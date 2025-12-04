#include <iostream>
using namespace std;
using ll = long long;
int n, m;
int arr[10];
bool iuse[10];

void fnc(int k, int j)
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
    int i = j;
    for (; i <= n; i++)
    {
        if (!iuse[i])
        {
            arr[k] = i;
            iuse[i] = true;
            fnc(k + 1, i);
            iuse[i] = false;
        }
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