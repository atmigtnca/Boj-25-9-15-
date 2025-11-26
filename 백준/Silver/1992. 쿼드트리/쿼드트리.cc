#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
vector<string> vid;

void fnc(int N, int y, int x)
{
    char srtcol = vid[y][x];
    bool chk = true;
    for (int i = y; i < y + N; i++)
    {
        for (int j = x; j < x + N; j++)
        {
            if (vid[i][j] != srtcol)
            {
                chk = false;

                break;
            }
        }
        if (!chk)
        {
            cout << '(';
            break;
        }
    }
    if (chk)
    {
        cout << srtcol - '0';
        return;
    }
    int div = N / 2;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            fnc(div, y + i * div, x + j * div);
        }
    }
    cout << ')';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vid.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> vid[i];
    }

    fnc(N, 0, 0);
    cout << '\n';

    return 0;
}