#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
vector<bool> set;
int m;

void solve()
{
    string ipt;
    int x;
    cin >> ipt;

    if (ipt == "add")
    {
        cin >> x;
        set[x] = 1;
    }
    else if (ipt == "remove")
    {
        cin >> x;
        set[x] = 0;
    }
    else if (ipt == "check")
    {
        cin >> x;
        if (set[x] == 1)
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
    else if (ipt == "toggle")
    {
        cin >> x;
        set[x] = (set[x] == 0) ? 1 : 0;
    }
    else if (ipt == "all")
    {
        fill(set.begin(), set.end(), 1);
    }
    else if (ipt == "empty")
    {
        fill(set.begin(), set.end(), 0);
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

    set.resize(22, 0);
    input();

    return 0;
}