#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void chg(string& b)
{
    for (auto& mem : b)
    {
        if (mem == 46 || mem == 79)
        {
            continue;
        }
        else if (mem == 124)
        {
            mem = 45;
        }
        else if (mem == 45)
        {
            mem = 124;
        }
        else if (mem == 92)
        {
            mem = 47;
        }
        else if (mem == 47)
        {
            mem = 92;
        }
        else if (mem == 62)
        {
            mem = 94;
        }
        else if (mem == 94)
        {
            mem = 60;
        }
        else if (mem == 60)
        {
            mem = 118;
        }
        else if (mem == 118)
        {
            mem = 62;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> milk(n);
    vector<string> out(m);

    string a;
    for (size_t i = 0; i < n; ++i)
    {
        cin >> a;
        chg(a);
        milk[i] = a;
    }

    for (size_t a = 0; a < m; ++a)
    {
        for (size_t b = 0; b < n; ++b)
        {
            out[m - a - 1] += milk[b][a];
        }
    }

    for (auto& cocoa : out)
    {
        cout << cocoa << '\n';
    }

    return 0;
}