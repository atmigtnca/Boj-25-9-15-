#include <deque>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> dble;
    int n;
    cin >> n;

    string cmd;
    for (int i = 0; i < n; i++)
    {
        int a;
        int emp = (dble.empty() ? 1 : 0);
        cin >> cmd;

        if (cmd == "push_front")
        {
            cin >> a;
            dble.push_front(a);
        }
        else if (cmd == "push_back")
        {
            cin >> a;
            dble.push_back(a);
        }
        else if (cmd == "pop_front")
        {
            if (!emp)
            {
                cout << dble.front() << '\n';
                dble.pop_front();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (cmd == "pop_back")
        {
            if (!emp)
            {
                cout << dble.back() << '\n';
                dble.pop_back();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (cmd == "size")
        {
            cout << (int)dble.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << emp << '\n';
        }
        else if (cmd == "front")
        {
            cout << (!emp ? dble.front() : -1) << '\n';
        }
        else if (cmd == "back")
        {
            cout << (!emp ? dble.back() : -1) << '\n';
        }
    }

    return 0;
}