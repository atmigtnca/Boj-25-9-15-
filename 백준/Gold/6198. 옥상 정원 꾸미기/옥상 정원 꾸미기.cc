#include <iostream>
#include <stack>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> tower;

    ll rst = 0;
    for (size_t i = 0; i < n; i++)
    {
        ll add = 0;
        int ip;
        cin >> ip;
        while (!tower.empty())
        {
            int srt = tower.top();
            if (srt <= ip)
            {
                tower.pop();
            }
            else if (srt >= ip)
            {
                rst += tower.size();
                break;
            }
        }
        tower.push(ip);
    }

    cout << rst << '\n';

    return 0;
}