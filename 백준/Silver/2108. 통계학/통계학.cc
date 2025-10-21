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

    ll in;
    for (size_t i = 0; i < nums.size(); i++)
    {
        cin >> in;
        nums[i] = in;
        all += in;
        if (cut.find(in) == cut.end())
        {
            cut.insert({in, 0});
            continue;
        }
        ++cut[in];
    }

    sort(nums.begin(), nums.end());

    ll th, num1, num2, it1Num;
    auto it1 = max_element(cut.begin(), cut.end(), [](auto& a, auto& b)
                           { return a.second < b.second; });
    num1 = it1->second;
    it1Num = it1->first;
    cut.erase(it1);
    auto it2 = max_element(cut.begin(), cut.end(), [](auto& a, auto& b)
                           { return a.second < b.second; });
    num2 = it2->second;

    if (num1 != num2 || n == 1)
    {
        th = it1Num;
    }
    else
    {
        th = it2->first;
    }

    ll fr = round((double)all / n);
    ll se = nums[(n / 2)];
    ll fo = nums[n - 1] - nums[0];

    cout << fr << '\n' << se << '\n' << th << '\n' << fo << '\n';

    return 0;
}