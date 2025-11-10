#include <iostream>
#include <string>
using namespace std;
using ll = long long;

bool self(int a)
{
    int nums = a;
    bool rst = false;
    while (a--)
    {
        int all = a;
        string chr = to_string(a);
        for (auto mem : chr)
        {
            all += mem - '0';
        }
        if (all == nums)
        {
            rst = true;
            break;
        }
    }
    return rst;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int srt = 1;
    while (srt != 10000)
    {
        bool sf = self(srt);
        if (!sf)
        {
            cout << srt << '\n';
        }
        srt++;
    }

    return 0;
}