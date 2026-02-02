#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;
const double PI = 3.141592653589793;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int w, h, r;

    cin >> w >> h >> r;
    double rst = (w * h) - (PI * r * r / 4);
    cout << rst << '\n';

    return 0;
}