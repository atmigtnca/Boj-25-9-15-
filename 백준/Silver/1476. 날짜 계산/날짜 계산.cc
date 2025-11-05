#include <iostream>
using namespace std;
using ll = long long;

int e, s, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> e >> s >> m;

    int first = 1, second = 1, third = 1;
    int cut = 1;
    while (true)
    {
        if (e == first && s == second && m == third)
        {
            break;
        }
        first += first >= 15 ? -14 : 1;
        second += second >= 28 ? -27 : 1;
        third += third >= 19 ? -18 : 1;

        cut++;
    }

    cout << cut << '\n';

    return 0;
}