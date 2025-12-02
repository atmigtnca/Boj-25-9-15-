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

    string tmp = "";
    int rst = 0;
    bool chk = false;

    for (size_t i = 0; i <= ipt.size(); i++)
    {
        if (ipt[i] == '-' || ipt[i] == '+' || i == ipt.size())
        {
            int num = stoi(tmp);

            if (chk)
            {
                rst -= num;
            }
            else
            {
                rst += num;
            }

            if (ipt[i] == '-')
            {
                chk = true;
            }
            tmp = "";
        }
        else
        {
            tmp += ipt[i];
        }
    }

    cout << rst << '\n';

    return 0;
}