#include <iostream>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, k;
    int ipt;
    int aln = 0;

    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> ipt;
        aln += (ipt + 1) / 2.0;
    }

    if (aln < n)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    return 0;
}