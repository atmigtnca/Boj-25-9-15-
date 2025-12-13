#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string ipt;
    cin >> ipt;

    int point = 1, rst = 0;

    for (size_t i = 0; i < ipt.size(); i++)
    {
        if (i == 0)
        {
            rst += point;
            continue;
        }

        if (ipt[i] > ipt[i - 1])
        {
            point++;
        }
        else
        {
            point = 1;
        }
        
        rst += point;
    }

    cout << rst << '\n';

    return 0;
}