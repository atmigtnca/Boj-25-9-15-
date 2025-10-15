#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> fb(3);

    for (size_t i = 0; i < 3; i++)
    {
        cin >> fb[i];
    }

    int idx = 2;
    while (idx >= 0)
    {
        if (fb[idx][0] <= '9' && '0' <= fb[idx][0])
        {
            break;
        }
        --idx;
    }

    int rst = stoi(fb[idx]) + (3 - idx);

    bool fixx = rst % 3, buxx = rst % 5;

    if (fixx == 0 && buxx == 0)
    {
        cout << "FizzBuzz" << '\n';
    }
    else if (fixx == 0)
    {
        cout << "Fizz" << '\n';
    }
    else if (buxx == 0)
    {
        cout << "Buzz" << '\n';
    }
    else
    {
        cout << rst << '\n';
    }

    return 0;
}