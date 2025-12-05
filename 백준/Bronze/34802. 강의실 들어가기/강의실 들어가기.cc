#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int tme[2];

void fnc(int d)
{
    string ipt, tmp = "";
    cin >> ipt;

    int mut = 3600;
    for (int i = 0; i < 8; i++)
    {
        tmp += ipt[i];
        if (tmp.size() == 2)
        {
            tme[d] += stoi(tmp) * mut;
            mut /= 60;
            i++;
            tmp = "";
        }
    }
}

int rstfnc()
{
    int t;
    double k;
    cin >> t >> k;
    t *= (1 - (k / 100));

    tme[0] += t;

    if (tme[0] <= tme[1])
    {
        return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    fnc(0);
    fnc(1);

    cout << rstfnc() << '\n';

    return 0;
}