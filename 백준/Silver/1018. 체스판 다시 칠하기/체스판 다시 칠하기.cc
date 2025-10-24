#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void clr(vector<vector<int>>& che, int& mIx, int row)
{
    int col = 0, zeorst, onerst;
    while (true)
    {
        zeorst = 0, onerst = 0;
        if (col + 8 > che[0].size())
        {
            break;
        }
        for (size_t i = 0; i < 8; i++)
        {
            for (size_t j = 0; j < 8; j++)
            {
                int x = col + j, y = row + i, one = ((i + j + 1) % 2),
                    zero = ((i + j) % 2);
                if (che[y][x] != one)
                {
                    ++onerst;
                }
                if (che[y][x] != zero)
                {
                    ++zeorst;
                }
            }
        }
        ++col;
        mIx = min(mIx, (zeorst >= onerst ? onerst : zeorst));
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> ches(n, vector<int>(m, 0));

    string wb;
    for (size_t i = 0; i < n; i++)
    {
        cin >> wb;
        for (size_t j = 0; j < m; j++)
        {
            ches[i][j] = (wb[j] == 'B');
        }
    }

    int mIx = 64;

    for (size_t row = 0; row + 8 <= n; row++)
    {
        clr(ches, mIx, row);
    }

    cout << mIx << '\n';

    return 0;
}