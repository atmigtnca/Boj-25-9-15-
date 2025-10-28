#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b != 0 ? gcd(b, a % b) : a; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        ll rst = 0;
        int m;
        cin >> m;
        vector<ll> cse(m);
        for (size_t j = 0; j < m; j++)
        {
            cin >> cse[j];
            for (size_t k = 0; k < j; k++)
            {
                rst += gcd(cse[j], cse[k]);
            }
        }
        cout << rst << '\n';
    }

    return 0;
}