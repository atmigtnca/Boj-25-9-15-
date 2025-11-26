#include <iostream>
using namespace std;
using ll = long long;
int par[130][130];
int blu, wht;

void divfnc(int x, int y, int N)
{
    int srtcol = par[y - 1][x - 1];
    bool chk = true;
    if (N == 0)
    {
        return;
    }
    for (int i = y - N; i < y; i++)
    {
        for (int j = x - N; j < x; j++)
        {
            if (par[i][j] != srtcol)
            {
                chk = false;
            }
        }
        if (!chk)
        {
            break;
        }
    }
    if (chk)
    {
        if (srtcol == 1)
        {
            blu++;
        }
        else
        {
            wht++;
        }
        return;
    }
    int haf = N / 2;
    divfnc(x - haf, y, haf);
    divfnc(x - haf, y - haf, haf);
    divfnc(x, y - haf, haf);
    divfnc(x, y, haf);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> par[i][j];
        }
    }

    divfnc(N, N, N);

    cout << wht << '\n' << blu << '\n';

    return 0;
}