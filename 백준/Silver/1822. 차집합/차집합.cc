#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<int> a_ary, b_ary, rst_ary;

void input()
{
    int a, b;
    cin >> a >> b;

    a_ary.resize(a);
    b_ary.resize(b);

    for (size_t i = 0; i < a; i++)
    {
        int t;
        cin >> t;
        a_ary[i] = t;
    }
    for (size_t i = 0; i < b; i++)
    {
        int t;
        cin >> t;
        b_ary[i] = t;
    }
}

void solve()
{
    sort(a_ary.begin(), a_ary.end());
    sort(b_ary.begin(), b_ary.end());

    for (size_t i = 0; i < a_ary.size(); i++)
    {
        bool chk = binary_search(b_ary.begin(), b_ary.end(), a_ary[i]);
        if (!chk)
        {
            rst_ary.push_back(a_ary[i]);
        }
    }
}

void output()
{
    cout << rst_ary.size() << '\n';
    if (rst_ary.size() > 0)
    {
        for (size_t i = 0; i < rst_ary.size(); i++)
        {
            cout << rst_ary[i] << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
    output();

    return 0;
}
