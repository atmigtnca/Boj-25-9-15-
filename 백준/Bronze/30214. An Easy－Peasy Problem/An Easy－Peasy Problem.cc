#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if (b % 2)
    {
        ++b;
    }

    if (b / 2 <= a)
    {
        cout << 'E' << '\n';
    }
    else
    {
        cout << 'H' << '\n';
    }

    return 0;
}