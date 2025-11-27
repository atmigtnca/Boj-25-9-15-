#include <iostream>
using namespace std;
using ll = long long;
int num, r, c;

void fnc(int N, int y, int x)
{
    if (N == 1)
    {
        return;
    }
    int div = N / 2;
    int pus = div * div;
    if (r < y + div && c < x + div)
    {
        fnc(div, y, x);
    }
    else if (r < y + div && c >= x + div)
    {
        num += pus;
        fnc(div, y, x + div);
    }
    else if (r >= y + div && c < x + div)
    {
        num += 2 * pus;
        fnc(div, y + div, x);
    }
    else
    {
        num += 3 * pus;
        fnc(div, y + div, x + div);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N >> r >> c;
    int siz = 1 << N;

    fnc(siz, 0, 0);

    cout << num << '\n';

    return 0;
}