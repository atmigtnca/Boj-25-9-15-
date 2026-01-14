#include <iostream>
using namespace std;
using ll = long long;
int bset;
int m;

void solve()
{
    char ipt[7];
    int x;
    cin >> ipt;

    if (ipt[1] == 'd')
    {
        cin >> x;
        bset |= (1 << (x - 1));
    }
    else if (ipt[0] == 'r')
    {
        cin >> x;
        bset &= (~(1 << (x - 1)));
    }
    else if (ipt[0] == 'c')
    {
        cin >> x;
        if ((bset >> (x - 1)) & 1)
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }
    else if (ipt[0] == 't')
    {
        cin >> x;
        bset ^= (1 << (x - 1));
    }
    else if (ipt[1] == 'l')
    {
        bset = 0xfffff;
    }
    else
    {
        bset = 0;
    }
}

void input()
{
    cin >> m;
    while (m--)
    {
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();

    return 0;
}