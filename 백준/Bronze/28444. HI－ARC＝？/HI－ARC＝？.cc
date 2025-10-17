#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int h, i, a, r, c;
    cin >> h >> i >> a >> r >> c;

    int rst = (h * i) - (a * r * c);

    cout << rst << '\n';

    return 0;
}