#include <iostream>
using namespace std;
using ll = long long;

void fnc(int le)
{
    if (le == 1)
    {
        cout << '-';
        return;
    }
    int div = le / 3;
    fnc(div);
    for (int i = 0; i < div; i++)
    {
        cout << ' ';
    }
    fnc(div);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int a;
    while (cin >> a)
    {
        int mu = 1;
        for (int i = 0; i < a; i++)
        {
            mu *= 3;
        }
        fnc(mu);
        cout << '\n';
    }

    return 0;
}