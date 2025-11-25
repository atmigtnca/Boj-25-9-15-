#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int cut;

int recu(const string& s, int l, int r)
{
    cut++;
    if (l >= r)
    {
        return 1;
    }
    else if (s[l] != s[r])
    {
        return 0;
    }
    else
    {
        return recu(s, l + 1, r - 1);
    }
}

int pal(const string& s) { return recu(s, 0, s.size() - 1); }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string ip;
        cin >> ip;
        cut = 0;
        cout << pal(ip) << ' ' << cut << '\n';
    }

    return 0;
}