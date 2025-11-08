#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;

    vector<int> nums(10, 0);

    for (size_t i = 0; i < n.size(); i++)
    {
        int a = n[i] - '0';
        nums[a]++;
    }

    int tmp = round((nums[6] + nums[9]) / 2.0);
    nums[6] = tmp;
    nums[9] = 0;

    auto it = max_element(nums.begin(), nums.end());
    cout << *it << '\n';

    return 0;
}