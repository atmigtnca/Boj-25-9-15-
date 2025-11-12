#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    stack<pair<int, int>> base;

    int n;
    cin >> n;

    int input;
    for (size_t i = 0; i < n; i++)
    {
        cin >> input;

        if (i == 0)
        {
            cout << 0 << ' ';
        }
        while (!base.empty())
        {
            if (base.top().first > input)
            {
                cout << base.top().second + 1 << ' ';
                break;
            }
            else if (base.size() == 1)
            {
                cout << 0 << ' ';
            }
            base.pop();
        }
        base.push({input, i});
    }
    cout << '\n';

    return 0;
}