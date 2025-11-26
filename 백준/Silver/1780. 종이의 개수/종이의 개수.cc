#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<vector<int>> par;
int rst[3];  // -1,0,1

void fnc(int x, int y, int N)
{
    int srtcol = par[y][x];
    bool chk = true;
    if (N == 0)
    {
        return;
    }
    for (int i = y; i < y + N; i++)
    {
        for (int j = x; j < x + N; j++)
        {
            if (par[i][j] != srtcol)
            {
                chk = false;
                break;
            }
        }
        if (!chk)
        {
            break;
        }
    }
    if (chk)
    {
        rst[srtcol + 1]++;
        return;
    }
    int div = N / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fnc(x + j * div, y + i * div, div);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    par.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> par[i][j];
        }
    }

    fnc(0, 0, N);

    for (int i = 0; i < 3; i++)
    {
        cout << rst[i] << '\n';
    }

    return 0;
}