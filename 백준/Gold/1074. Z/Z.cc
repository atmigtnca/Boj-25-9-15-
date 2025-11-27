#include <iostream>
using namespace std;
using ll = long long;

int fnc(int N, int r, int c)
{
    if (N == 1)
    {
        return 0;
    }
    int div = N / 2;
    int pus = div * div;
    if (r < div && c < div)
    {
        return fnc(div, r, c);
    }
    else if (r < div && c >= div)
    {
        return pus + fnc(div, r, c - div);
    }
    else if (r >= div && c < div)
    {
        return 2 * pus + fnc(div, r - div, c);
    }
    else
    {
        return 3 * pus + fnc(div, r - div, c - div);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, r, c;
    cin >> N >> r >> c;
    int siz = 1 << N;

    cout << fnc(siz, r, c) << '\n';

    return 0;
}