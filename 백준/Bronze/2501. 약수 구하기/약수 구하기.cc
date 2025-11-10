#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> num;

    for (size_t i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            int ot = n / i;
            if (ot != i)
            {
                num.push_back(ot);
            }
            num.push_back(i);
        }
    }

    sort(num.begin(), num.end());

    if (num.size() >= k)
    {
        cout << num[k - 1] << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }

    return 0;
}