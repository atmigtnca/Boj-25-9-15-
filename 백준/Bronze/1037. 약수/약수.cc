#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nat(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> nat[i];
    }

    sort(nat.begin(), nat.end());

    int rst = nat[0] * nat[nat.size() - 1];

    cout << rst << '\n';

    return 0;
}
