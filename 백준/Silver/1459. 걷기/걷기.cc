#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
ll X, Y, W, S;
ll rst[3];

void iptfnc()
{
    cin >> X >> Y >> W >> S;
    if (X < Y)
    {
        ll tmp = X;
        X = Y;
        Y = tmp;
    }
}

ll rstfnc()
{
    rst[0] = (X + Y) * W;

    if ((X - Y) % 2)
    {
        rst[1] = ((X - 1) * S) + W;
    }
    else
    {
        rst[1] = X * S;
    }

    rst[2] = X * W + Y * (S - W);

    sort(rst, rst + 3);

    return rst[0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    iptfnc();
    cout << rstfnc() << '\n';

    return 0;
}