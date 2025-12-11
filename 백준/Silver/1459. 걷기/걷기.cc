#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
ll X, Y, W, S;

void iptfnc()
{
    cin >> X >> Y >> W >> S;
    if (X < Y)
    {
        swap(X, Y);
    }
}

ll rstfnc()
{
    ll case1, case2, case3;
    case1 = (X + Y) * W;

    if ((X - Y) % 2)
    {
        case2 = ((X - 1) * S) + W;
    }
    else
    {
        case2 = X * S;
    }

    case3 = X * W + Y * (S - W);

    return min({case1, case2, case3});
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    iptfnc();
    cout << rstfnc() << '\n';

    return 0;
}