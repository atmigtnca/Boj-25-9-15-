#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int pout(int idx, queue<pair<int, int>> &prt, vector<int> &mlist)
{
    int cut = 0, sat = 1;
    while (sat)
    {
        if (prt.front().second == idx && prt.front().first >= mlist[0])
        {
            ++cut;
            sat = 0;
        }
        else if (prt.front().second == idx && prt.front().first < mlist[0])
        {
            prt.push(prt.front());
            prt.pop();
        }
        else if (prt.front().second != idx && prt.front().first >= mlist[0])
        {
            prt.pop();
            mlist.erase(mlist.begin());
            ++cut;
        }
        else if (prt.front().second != idx && prt.front().first < mlist[0])
        {
            prt.push(prt.front());
            prt.pop();
        }
    }
    return cut;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (size_t i = 0; i < n; ++i)
    {
        int k, idx;
        cin >> k >> idx;
        queue<pair<int, int>> prt;
        vector<int> mam;
        mam.reserve(k);
        for (size_t j = 0; j < k; ++j)
        {
            int fst;
            cin >> fst;
            prt.push({fst, j});
            mam.push_back(fst);
        }
        sort(mam.begin(), mam.end(), greater<int>());

        cout << pout(idx, prt, mam) << '\n';
    }

    return 0;
}