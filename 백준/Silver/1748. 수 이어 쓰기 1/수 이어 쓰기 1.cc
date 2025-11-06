#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int rst = 0;

    for (int i = 1; i <= n; i *= 10)
    {
        rst += n - i + 1;
    }
    cout << rst << '\n';

    return 0;
}