#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, idx = 0;
    cin >> n;
    string sbt, rst;
    cin >> sbt;

    int scut = 0, bcut = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (sbt[idx] == 's')
        {
            ++scut;
            idx += 8;
        }
        else if (sbt[idx] == 'b')
        {
            ++bcut;
            idx += 7;
        }
    }

    if (bcut > scut)
    {
        rst = "bigdata?";
    }
    else if (bcut < scut)
    {
        rst = "security!";
    }
    else
    {
        rst = "bigdata? security!";
    }

    cout << rst << '\n';

    return 0;
}
