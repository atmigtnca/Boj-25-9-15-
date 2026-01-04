#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int ipt[1000001];
int n;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ipt[i];
    }
}

void output()
{
    for (int i = 0; i < n; i++)
    {
        cout << ipt[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    sort(&ipt[0], &ipt[n]);
    output();

    return 0;
}
