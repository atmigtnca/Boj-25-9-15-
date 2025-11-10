#include <array>
#include <iostream>
using namespace std;
using ll = long long;
const int MAX = 10000;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    array<bool, MAX + 1> sou;
    for (size_t i = 0; i < MAX + 1; i++)
    {
        sou[i] = true;
    }
    sou[1] = false;
    for (size_t a = 2; a * a <= MAX; a++)
    {
        for (size_t b = a * a; b <= MAX; b += a)
        {
            sou[b] = false;
        }
    }

    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        int a = input / 2, b = input / 2;
        while (a > 0)
        {
            if (sou[a] && sou[b])
            {
                cout << a << ' ' << b << '\n';
                break;
            }
            a--, b++;
        }
    }

    return 0;
}