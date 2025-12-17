#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
vector<vector<string>> apt;
int visapt[33][33][33];
int L, R, C;
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct Cursor
{
    int Z;
    int Y;
    int X;
};
Cursor ed;
queue<Cursor> cur;

void bfsfnc()
{
    while (!cur.empty())
    {
        auto [cz, cy, cx] = cur.front();
        cur.pop();

        for (int i = 0; i < 6; i++)
        {
            int nz = cz + dz[i];
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (nz < 0 || nz >= L || ny < 0 || ny >= R || nx < 0 || nx >= C)
            {
                continue;
            }
            if (visapt[nz][ny][nx] != -1 || apt[nz][ny][nx] == '#')
            {
                continue;
            }
            cur.push({nz, ny, nx});
            visapt[nz][ny][nx] = visapt[cz][cy][cx] + 1;
            if (nz == ed.Z && ny == ed.Y && nx == ed.X)
            {
                cout << "Escaped in " << visapt[nz][ny][nx] << " minute(s).\n";
                return;
            }
        }
    }
    cout << "Trapped!\n";
    return;
}

void iptfnc()
{
    while (1)
    {
        cin >> L >> R >> C;
        if (L == 0)
        {
            break;
        }

        for (int a = 0; a < L; a++)
        {
            for (int b = 0; b < R; b++)
            {
                fill(visapt[a][b], visapt[a][b] + 33, -1);
            }
        }

        size_t sze = cur.size();
        while (sze--)
        {
            cur.pop();
        }
        
        apt.assign(L, vector<string>(R));
        for (int a = 0; a < L; a++)
        {
            for (int b = 0; b < R; b++)
            {
                cin >> apt[a][b];

                for (int c = 0; c < C; c++)
                {
                    if (apt[a][b][c] == 'S')
                    {
                        cur.push({a, b, c});
                        visapt[a][b][c] = 0;
                    }
                    else if (apt[a][b][c] == 'E')
                    {
                        ed.Z = a, ed.Y = b, ed.X = c;
                    }
                }
            }
        }

        bfsfnc();
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    iptfnc();

    return 0;
}