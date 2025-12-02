#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
vector<int> nums;
vector<char> plma;

int fid(int cur, string& ipt)
{
    int size = 0, tmp = cur;
    for (int i = cur; i < cur + 5; i++)
    {
        if ('0' > ipt[i] || ipt[i] > '9')
        {
            break;
        }
        size++;
    }

    int ten = pow(10, size - 1), rst = 0;
    for (int i = cur; i < cur + size; i++)
    {
        int num = ipt[i] - '0';
        rst += num * ten;
        ten /= 10;
    }

    nums.push_back(rst);
    if (cur + size < ipt.size())
    {
        plma.push_back(ipt[cur + size]);
    }
    return ++size;
}

void trans()
{
    plma.push_back('+');
    string ipt;
    cin >> ipt;

    int cur = 0;
    while (cur < ipt.size())
    {
        int len = fid(cur, ipt);
        cur += len;
    }
}

int cal()
{
    int rst = 0;
    int cur = nums.size();

    for (size_t i = 0; i < nums.size(); i++)
    {
        if (plma[i] == '+')
        {
            rst += nums[i];
            // cout << i << ' ' << nums[i] << "ppp\n";
        }
        else
        {
            for (int j = i; j < nums.size(); j++)
            {
                rst -= nums[j];
                // cout << j << ' ' << nums[j] << "mmm\n";
                if (plma[j + 1] == '-' || j == nums.size() - 1)
                {
                    i = j;
                    // cout << j + 1 << '\n';
                    break;
                }
            }
        }
    }

    return rst;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    nums.reserve(51);
    plma.reserve(31);

    trans();

    cout << cal() << '\n';

    return 0;
}