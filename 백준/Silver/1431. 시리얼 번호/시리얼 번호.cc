#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
vector<string> ary;
int n;

bool srlsort(string a, string b)
{
    if (a.size() != b.size())
    {
        return a.size() < b.size();
    }

    int adda = 0, addb = 0;

    for (size_t i = 0; i < a.size(); i++)
    {
        char tmp = a[i];
        if (tmp >= '0' && tmp <= '9')
        {
            adda += tmp - '0';
        }
    }
    for (size_t i = 0; i < b.size(); i++)
    {
        char tmp = b[i];
        if (tmp >= '0' && tmp <= '9')
        {
            addb += tmp - '0';
        }
    }

    if (adda != addb)
    {
        return adda < addb;
    }
    return a < b;
}

void output()
{
    for (auto mem : ary)
    {
        cout << mem << '\n';
    }
}

void input()
{
    cin >> n;
    ary.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ary[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    sort(ary.begin(), ary.end(), srlsort);
    output();

    return 0;
}