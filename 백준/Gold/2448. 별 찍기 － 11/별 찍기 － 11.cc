#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<vector<char>> tri;

void drw(int y, int x)
{
    tri[y][x] = '*';
    tri[y + 1][x + 1] = '*';
    tri[y + 1][x - 1] = '*';
    for (int i = 0; i < 5; i++)
    {
        tri[y + 2][x - 2 + i] = '*';
    }
}

void fnc(int C, int y, int x)
{
    if (C == 0)
    {
        drw(y, x);
        return;
    }
    int N = 3 * (1 << C) / 2;
    fnc(C - 1, y + N, x - N);
    fnc(C - 1, y + N, x + N);
    fnc(C - 1, y, x);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    tri.resize(N, vector<char>(N * 2, ' '));

    int cnt = N / 3;
    for (int i = 0; i <= 10; i++)
    {
        int tmp = cnt / (1 << i);
        if (tmp == 1)
        {
            cnt = i;
        }
    }

    fnc(cnt, 0, N - 1);

    for (auto mems : tri)
    {
        for (auto mem : mems)
        {
            cout << mem;
        }
        cout << '\n';
    }

    return 0;
}