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

    deque<int> cir(n);

    for (size_t i = 0; i < n; i++)
    {
        cir[i] = i + 1;
    }

    int rst = 0;
    for (size_t i = 0; i < m; i++)
    {
        bool mid = true;
        int a;
        cin >> a;

        for (size_t b = 0; b < n; b++)
        {
            if (b + 1 > (n + 1) / 2)
            {
                mid = false;
                break;
            }
            if (cir[b] == a)
            {
                break;
            }
        }
        // cout << i << ' ' << mid << '\n';

        while (true)
        {
            // for (auto mem : cir)
            // {
            //     cout << mem << ' ';
            // }
            // cout << '\n';

            if (cir.front() == a)
            {
                cir.pop_front();
                n--;
                break;
            }

            if (mid)
            {
                int tmp = cir.front();
                cir.push_back(tmp);
                cir.pop_front();
            }
            else if (!mid)
            {
                int tmp = cir.back();
                cir.push_front(tmp);
                cir.pop_back();
            }
            rst++;
        }
    }

    cout << rst << '\n';

    return 0;
}