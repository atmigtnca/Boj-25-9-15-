#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string tr;
    cin >> tr;

    long long rst = 0;
    int dp = 0;

    for (size_t i = 0; i < tr.size(); ++i)
    {
        if (tr[i] == '(')
            dp++;
        else
        {
            dp--;
            if (tr[i - 1] == '(')
                rst += dp;
        }
    }

    cout << rst << "\n";

    return 0;
}