#include <iostream>
using namespace std;
using ll = long long;

int fnc()
{
    int N;
    cin >> N;

    int tn = 0;
    while (N >= 0)
    {
        if (N % 5 == 0)
        {
            return tn + (N / 5);
        }
        N -= 3;
        tn++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cout << fnc() << '\n';

    return 0;
}