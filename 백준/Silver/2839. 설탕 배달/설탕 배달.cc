#include <iostream>
using namespace std;
using ll = long long;

int fnc()
{
    int N;
    int rst;
    cin >> N;

    int fn = N / 5, tn = (N % 5) / 3;

    while (1)
    {
        for (int i = 0; i < N / 3; i++)
        {
            if ((fn * 5) + (i * 3) == N)
            {
                tn = i;
                break;
            }
        }

        rst = (fn * 5) + (tn * 3);
        if (rst == N)
        {
            break;
        }
        else
        {
            fn--;
        }
        if (fn < 0)
        {
            if (N % 3 == 0)
            {
                return N / 3;
            }
            return -1;
        }
    }

    return fn + tn;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cout << fnc() << '\n';

    return 0;
}