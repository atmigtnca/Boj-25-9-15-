#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string rst;
    cin >> rst;

    for (size_t i = 0; i < rst.size(); i++)
    {
        if ('a' <= rst[i] && rst[i] <= 'z')
        {
            char opt = rst[i] - 32;
            cout << opt;
        }
        else
        {
            char opt = rst[i] + 32;
            cout << opt;
        }
    }
    cout << '\n';

    return 0;
}