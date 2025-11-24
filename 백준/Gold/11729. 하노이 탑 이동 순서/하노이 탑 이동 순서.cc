#include <iostream>
using namespace std;
using ll = long long;

void han(int n, char from, char by, char to)
{
    if (n == 1)
    {
        cout << from << ' ' << to << '\n';
        return;
    }
    han(n - 1, from, to, by);
    cout << from << ' ' << to << '\n';
    han(n - 1, by, from, to);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    han(n, '1', '2', '3');

    return 0;
}