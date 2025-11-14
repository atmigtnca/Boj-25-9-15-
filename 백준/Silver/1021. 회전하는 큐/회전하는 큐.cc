#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    deque<int> cir;
    for (size_t i = 1; i <= n; i++)
    {
        cir.push_back(i);
    }

    int rst = 0;
    for (size_t i = 0; i < m; i++)
    {
        bool mid = true;
        int a;
        cin >> a;

        auto it = find(cir.begin(), cir.end(), a);
        int idx = it - cir.begin();
        if (idx >= (cir.size() + 1) / 2)
        {
            mid = false;
        }

        if (mid)
        {
            rst += idx;
            while (cir.front() != a)
            {
                cir.push_back(cir.front());
                cir.pop_front();
            }
        }
        else if (!mid)
        {
            rst += cir.size() - idx;
            while (cir.front() != a)
            {
                cir.push_front(cir.back());
                cir.pop_back();
            }
        }
        cir.pop_front();
    }

    cout << rst << '\n';

    return 0;
}