#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int n, m;
int ipt[10];
int arr[10];
bool iuse[10001];

void fnc(int k)
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
    for (int i = 0; i < n; i++)
    {
        int num = ipt[i];
        if (!iuse[num])
        {
            arr[k] = num;
            iuse[num] = true;
            fnc(k + 1);
            iuse[num] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> ipt[i];
    }
    sort(ipt, ipt + n);

    fnc(0);

    return 0;
}