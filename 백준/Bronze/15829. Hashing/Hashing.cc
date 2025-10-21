#include <iostream>
#include <string>
using namespace std;
using ll = long long;
#define SU 1234567891

ll rmd(ll a, ll b) { return (a * b) % SU; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    string hsg;
    cin >> hsg;

    ll mtp = 1, rst = 0;
    for (size_t i = 0; i < n; i++)
    {
        ll ap = hsg[i] - 'a' + 1;
        rst += rmd(ap, mtp);
        mtp = rmd(mtp, 31);
    }

    rst %= SU;

    cout << rst << '\n';

    return 0;
}