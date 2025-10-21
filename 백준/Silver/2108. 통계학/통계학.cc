#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, all = 0;
    cin >> n;
    map<ll, ll> cut;
    vector<ll> nums(n);
    vector<ll> maxNum;
    maxNum.reserve(n);

    ll in;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        cin >> in;
        nums[i] = in;
        all += in;
        ++cut[in];
    }

    sort(nums.begin(), nums.end());

    ll th, maxIum;
    auto it1 = max_element(cut.begin(), cut.end(), [](auto& a, auto& b)
                           { return a.second < b.second; });

    maxIum = it1->second;

    for (const auto& max : cut)
    {
        if (max.second == maxIum)
        {
            maxNum.push_back(max.first);
        }
    }

    if (maxNum.size() >= 2)
    {
        th = maxNum[1];
    }
    else
    {
        th = maxNum[0];
    }

    ll fr = round((double)all / n);
    ll se = nums[(n / 2)];
    ll fo = nums[n - 1] - nums[0];

    cout << fr << '\n' << se << '\n' << th << '\n' << fo << '\n';

    return 0;
}