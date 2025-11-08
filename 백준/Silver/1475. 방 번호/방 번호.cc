#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;

    vector<int> nums(10, 0);

    for (char chr : n)
    {
        int a = chr - '0';
        nums[a]++;
    }

    int tmp = (nums[6] + nums[9] + 1) / 2;
    nums[6] = tmp;
    nums[9] = 0;

    auto it = max_element(nums.begin(), nums.end());
    cout << *it << '\n';

    return 0;
}