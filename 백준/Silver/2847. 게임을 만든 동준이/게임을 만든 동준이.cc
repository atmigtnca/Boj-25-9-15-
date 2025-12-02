#include <iostream>
using namespace std;
using ll = long long;
int lev[101];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, rst = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> lev[i];
    }

    for (int i = N - 2; i >= 0; i--)
    {
        int srt = lev[i + 1];
        while (lev[i] >= srt)
        {
            rst++;
            lev[i]--;
        }
    }

    cout << rst << '\n';

    return 0;
}