#include <iostream>
#include <queue>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    queue<int> que;

    string ipt;
    for (size_t i = 0; i < n; i++)
    {
        bool rst = que.empty();

        cin >> ipt;

        if (ipt == "push")
        {
            int num;
            cin >> num;
            que.push(num);
        }
        else if (ipt == "front")
        {
            if (rst != 1)
            {
                cout << que.front() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (ipt == "back")
        {
            if (rst != 1)
            {
                cout << que.back() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (ipt == "size")
        {
            cout << que.size() << '\n';
        }
        else if (ipt == "pop")
        {
            if (rst != 1)
            {
                cout << que.front() << '\n';
                que.pop();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else
        {
            cout << rst << '\n';
        }
    }

    return 0;
}