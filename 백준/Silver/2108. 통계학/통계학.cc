#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, all = 0;
    cin >> n;
    vector<ll> nums(n);
    vector<ll> mod(8001, 0);

    ll in, minIdx = 4000, maxIdx = -4000;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        cin >> in;
        nums[i] = in;
        all += in;
        ++mod[in + 4000];
        if (in < minIdx)
        {
            minIdx = in;
        }
        if (in > maxIdx)
        {
            maxIdx = in;
        }
    }
    minIdx += 4000, maxIdx += 4000;

    vector<ll> modNum;
    modNum.reserve(maxIdx - minIdx + 1);

    ll max = 0;
    for (size_t i = minIdx; i <= maxIdx; i++)
    {
        if (mod[i] > max)
        {
            max = mod[i];
        }
    }

    for (size_t i = minIdx; i <= maxIdx; i++)
    {
        if (mod[i] == max)
        {
            modNum.push_back(i - 4000);
        }
    }

    sort(nums.begin(), nums.end());

    ll fr, se, th, fo, moMax = 0;

    if (modNum.size() >= 2)
    {
        th = modNum[1];
    }
    else
    {
        th = modNum[0];
    }

    fr = round((double)all / n);
    se = nums[(n / 2)];
    fo = nums[n - 1] - nums[0];

    cout << fr << '\n' << se << '\n' << th << '\n' << fo << '\n';

    return 0;
}