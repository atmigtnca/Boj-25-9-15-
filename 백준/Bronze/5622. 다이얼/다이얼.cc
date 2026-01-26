#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int ary[] = {3, 3, 3, 4, 4, 4, 5, 5, 5, 6,  6,  6,  7,
             7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10};
int rst = 0;
string ipt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> ipt;
    for (size_t i = 0; i < ipt.size(); i++)
    {
        int a = ipt[i] - 'A';
        rst += ary[a];
    }

    cout << rst << '\n';

    return 0;
}