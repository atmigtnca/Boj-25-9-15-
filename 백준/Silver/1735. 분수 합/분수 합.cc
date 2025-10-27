#include <iostream>
using namespace std;
using ll = long long;

int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a1, a2, b1, b2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;

    int mot = a2 * b2, son = (a1 * b2) + (b1 * a2);

    int div = gcd(son, mot);
    mot /= div, son /= div;

    cout << son << ' ' << mot << '\n';
    return 0;
}