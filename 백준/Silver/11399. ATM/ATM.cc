#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, rst = 0;
    cin >> N;
    vector<int> mon;
    mon.reserve(N);

    while (N--)
    {
        int ipt;
        cin >> ipt;
        mon.push_back(ipt);
    }

    sort(mon.begin(), mon.end());

    int tmp = 0;
    for (size_t i = 0; i < mon.size(); i++)
    {
        tmp += mon[i];
        rst += tmp;
    }

    cout << rst << '\n';

    return 0;
}