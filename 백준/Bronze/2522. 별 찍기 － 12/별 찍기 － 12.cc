#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, star = 0;
    cin >> n;

    for (size_t i = 1; i <= (2 * n) - 1; ++i)
    {
        star += i <= n ? 1 : -1;
        for (size_t a = 0; a < n - star; ++a)
        {
            cout << ' ';
        }
        for (size_t b = 0; b < star; ++b)
        {
            cout << '*';
        }
        cout << '\n';
    }
    return 0;
}