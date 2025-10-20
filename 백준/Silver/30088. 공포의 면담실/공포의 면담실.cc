#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, ct;
    cin >> n;
    vector<int> goHm(n, 0);

    for (size_t i = 0; i < n; ++i)
    {
        cin >> ct;
        for (size_t j = 0; j < ct; ++j)
        {
            int a;
            cin >> a;
            goHm[i] += a;
        }
    }

    sort(goHm.begin(), goHm.end());

    ll rst = 0, ad = 0;

    for (size_t i = 0; i < n; i++)
    {
        ad += goHm[i];
        rst += ad;
    }

    cout << rst << '\n';

    return 0;
}