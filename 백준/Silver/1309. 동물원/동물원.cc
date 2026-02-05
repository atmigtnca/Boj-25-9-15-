#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> ary;
int n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    ary.resize(n);
    ary[0] = 3;
    ary[1] = 7;

    for (int i = 2; i < n; i++)
    {
        ary[i] = (2 * ary[i - 1] + ary[i - 2]) % 9901;
    }

    cout << ary[n - 1] << '\n';

    return 0;
}