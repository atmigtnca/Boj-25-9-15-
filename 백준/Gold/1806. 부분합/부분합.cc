#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> ary;
int n, s;

void twopointer()
{
    int ecur = 0;
    int rst = 2e9;
    int add = ary[0];

    for (int scur = 0; scur < n; scur++)
    {
        while (ecur < n && add < s)
        {
            ecur++;
            if (ecur != n)
            {
                add += ary[ecur];
            }
        }
        if (ecur == n)
        {
            break;
        }
        rst = min(rst, ecur - scur + 1);
        add -= ary[scur];
    }
    if (rst == 2e9)
    {
        rst = 0;
    }
    cout << rst << '\n';
}

void input()
{
    cin >> n >> s;
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
    twopointer();

    return 0;
}