#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<vector<char>> grp;

void fnc(int N, int y, int x)
{
    if (N == 1)
    {
        grp[y][x] = '*';
        return;
    }
    int div = N / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
            {
                continue;
            }
            fnc(div, y + i * div, x + j * div);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    grp.resize(N, vector<char>(N, ' '));

    fnc(N, 0, 0);

    for (auto mems : grp)
    {
        for (auto mem : mems)
        {
            cout << mem;
        }
        cout << '\n';
    }

    return 0;
}