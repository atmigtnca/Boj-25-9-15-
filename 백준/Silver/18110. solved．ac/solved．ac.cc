#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long all = 0, n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> svd(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> svd[i];
        all += svd[i];
    }

    double io = n * 0.15;
    int k = round(io);

    sort(svd.begin(), svd.end());

    for (size_t i = 0; i < k; i++)
    {
        all -= svd[i] + svd[n - i - 1];
    }

    int rst = round(all / (float)(n - (k * 2)));
    cout << rst << '\n';

    return 0;
}