#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int n;

void input()
{
    cin >> n;
    while (n--)
    {
        int p, c = 0;
        string name = "";
        cin >> p;
        while (p--)
        {
            int tmpi;
            string tmpc;
            cin >> tmpi >> tmpc;
            if (tmpi > c)
            {
                c = tmpi;
                name = tmpc;
            }
        }
        cout << name << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();

    return 0;
}