#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int n, m;
vector<int> ipt;
vector<int> rst;

void fnc(int k, int srt)
{
    if (k == m)
    {
        for (auto mem : rst)
        {
            cout << mem << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = srt; i < n; i++)
    {
        int num = ipt[i];
        rst[k] = num;
        fnc(k + 1, i);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    ipt.resize(n);
    rst.resize(m);

    for (int i = 0; i < n; i++)
    {
        cin >> ipt[i];
    }

    sort(ipt.begin(), ipt.end());

    fnc(0, 0);

    return 0;
}