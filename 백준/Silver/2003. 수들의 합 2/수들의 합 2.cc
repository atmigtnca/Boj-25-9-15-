#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> ary;
int n, m, rst = 0;

void twopt()
{
    int s = 0;
    int e = 0;
    int add = ary[0];
    while (s <= n && e <= n)
    {
        if (add < m)
        {
            e++;
            add += ary[e];
        }
        else
        {
            if (add == m)
            {
                rst++;
            }
            add -= ary[s];
            s++;
        }
    }
}

void input()
{
    cin >> n >> m;
    ary.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ary[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    twopt();
    cout << rst << '\n';

    return 0;
}