#include <array>
#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    array<int, 5> dou;
    for (size_t i = 0; i < 5; i++)
    {
        cin >> dou[i];
    }

    int str = 1, rst;
    while (true)
    {
        int cut = 0;
        for (size_t i = 0; i < 5; i++)
        {
            int n = str % dou[i];
            if (n == 0)
            {
                cut++;
            }
        }
        if (cut >= 3)
        {
            rst = str;
            break;
        }
        str++;
    }
    cout << rst << '\n';

    return 0;
}