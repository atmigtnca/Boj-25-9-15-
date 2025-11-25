#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int MIN = 1001;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int left = x;
    int right = w - x;
    int up = h - y;
    int down = y;
    MIN = min(MIN, left);
    MIN = min(MIN, right);
    MIN = min(MIN, up);
    MIN = min(MIN, down);

    cout << MIN << '\n';

    return 0;
}