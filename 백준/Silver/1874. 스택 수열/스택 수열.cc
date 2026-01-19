#include <iostream>
#include <stack>
#include <vector>
using namespace std;
using ll = long long;
vector<char> rst;
vector<int> ary;
int n;

void output()
{
    for (auto mem : rst)
    {
        cout << mem << '\n';
    }
}

bool solve()
{
    int cur = 0;
    stack<int> mystack;
    for (int i = 1; i <= n; i++)
    {
        mystack.push(i);
        rst.push_back('+');
        while (!mystack.empty() && mystack.top() == ary[cur])
        {
            mystack.pop();
            rst.push_back('-');
            cur++;
        }
    }
    if (cur == n)
    {
        return true;
    }
    return false;
}

void input()
{
    cin >> n;
    ary.resize(n + 1);
    rst.reserve(n * 2 + 1);
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
    bool chk = solve();
    if (chk)
    {
        output();
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}
