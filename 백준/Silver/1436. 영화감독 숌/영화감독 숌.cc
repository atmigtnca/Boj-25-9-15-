#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int tripleSix(int num)
{
    int startNum = 0, count = 0;
    while (num != count)
    {
        startNum++;
        string str = to_string(startNum);
        for (int i = str.size() - 1; i >= 0; i--)
        {
            if (str[i] == '6')
            {
                if (i >= 2 && str[i - 1] == '6' && str[i - 2] == '6')
                {
                    count++;
                    break;
                }
            }
        }
    }
    return startNum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;
    cout << tripleSix(num) << '\n';

    return 0;
}