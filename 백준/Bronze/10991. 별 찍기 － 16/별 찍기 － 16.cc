#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    if (n == 1)
    {
        cout << '*' << '\n';
        return 0;
    }

    for (size_t i = 1; i <= n; i++)
    {
        for (size_t a = 0; a < n - i; a++)
        {
            cout << ' ';
        }
        for (size_t b = 0; b < i; b++)
        {
            cout << "*";
            if (b != i - 1)
            {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
