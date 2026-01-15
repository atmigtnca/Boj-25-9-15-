#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;
using ll = long long;
using psi = pair<string, int>;
map<string, int> les, lok;
int n, m;

void output()
{
    cout << lok.size() << '\n';
    for (auto mem : lok)
    {
        cout << mem.first << '\n';
    };
}

void check(const string& ipt)
{
    auto it = les.find(ipt);
    if (it == les.end())
    {
        return;
    }
    lok.insert(psi(ipt, 0));
}

void input()
{
    string iptS;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> iptS;
        les.insert(psi(iptS, 0));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> iptS;
        check(iptS);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    output();

    return 0;
}