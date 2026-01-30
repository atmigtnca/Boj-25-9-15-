#include <iostream>
using namespace std;
using ll = long long;
int dim[11];
int n, rst = 0;

void fnc()
{
    double l;
    int b, s;
    for (int i = 0; i <= 10; i++)
    {
        cin >> dim[i];
    }
    cin >> n;
    while (n--)
    {
        cin >> b >> l >> s;
        if (l >= 2.0 && s >= 17)
        {
            rst += dim[b];
        }
    }
    cout << rst << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fnc();

    return 0;
}