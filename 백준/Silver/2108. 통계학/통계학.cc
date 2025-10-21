#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, all = 0;
    cin >> n;
    map<int, int> cut;
    vector<int> nums(n);
    vector<int> maxNum;
    maxNum.reserve(n);

    int in;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        cin >> in;
        nums[i] = in;
        all += in;
        ++cut[in];
    }

    sort(nums.begin(), nums.end());

    int th, maxIum;
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

    int fr = round((double)all / n);
    int se = nums[(n / 2)];
    int fo = nums[n - 1] - nums[0];

    cout << fr << '\n' << se << '\n' << th << '\n' << fo << '\n';

    return 0;
}