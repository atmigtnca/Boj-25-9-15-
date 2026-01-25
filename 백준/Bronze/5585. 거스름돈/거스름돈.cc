#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    int joi = 1000;
    int rst = 0;
    int smlcha[6] = {500, 100, 50, 10, 5, 1};

    cin >> n;
    joi -= n;

    for (int i = 0; i < 6; i++)
    {
        int chmod = joi % smlcha[i];
        int chdiv = joi / smlcha[i];

        if (chdiv)
        {
            rst += chdiv;
            joi = chmod;
        }
    }

    cout << rst << '\n';

    return 0;
}