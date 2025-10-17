#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b;
    cin >> a >> b;
    ll rst = (a + b) * (a - b);

    cout << rst << '\n';

    return 0;
}