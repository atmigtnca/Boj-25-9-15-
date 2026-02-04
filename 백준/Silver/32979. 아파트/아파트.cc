#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
queue<int> apt;
int n, t;

void input()
{
    cin >> n >> t;
    int cnt = n * 2;

    while (cnt--)
    {
        int ipt;
        cin >> ipt;
        apt.push(ipt);
    }
    while (t--)
    {
        int b;
        cin >> b;
        while (--b)
        {
            int tmp = apt.front();
            apt.pop();
            apt.push(tmp);
        }
        cout << apt.front() << ' ';
    }
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();

    return 0;
}