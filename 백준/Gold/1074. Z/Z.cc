#include <iostream>
using namespace std;
using ll = long long;
int num, r, c, rst;

void fnc(int N, int y, int x)
{
    if (y == r && x == c)
    {
        rst = num;
        return;
    }
    if (N == 1)
    {
        return;
    }
    int div = N / 2;
    int pus = div * div;
    int cut = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int dy = y + i * div;
            int dx = x + j * div;
            if (r - dy < div && r - dy >= 0 && c - dx < div && c - dx >= 0)
            {
                num += pus * cut;
                fnc(div, dy, dx);
            }
            cut++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N >> r >> c;
    int siz = 1 << N;

    fnc(siz, 0, 0);

    cout << rst << '\n';

    return 0;
}