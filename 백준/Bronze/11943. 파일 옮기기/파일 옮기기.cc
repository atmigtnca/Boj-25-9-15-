#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int a1, b1;
    int a2, b2;

    cin >> a1 >> b1;
    cin >> a2 >> b2;

    if (a1 + b2 < a2 + b1)
    {
        cout << a1 + b2 << '\n';
    }
    else
    {
        cout << a2 + b1 << '\n';
    }

    return 0;
}