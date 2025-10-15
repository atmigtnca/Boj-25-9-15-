#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> ysu(n);

    for (size_t i = 0; i < n; i++)
    {
        cin >> ysu[i];
    }

    sort(ysu.begin(), ysu.end(), greater<int>());

    cout << ysu[k - 1] << '\n';

    return 0;
}