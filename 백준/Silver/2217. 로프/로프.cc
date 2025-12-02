#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    vector<int> lin;
    lin.reserve(N);

    for (int i = 0; i < N; i++)
    {
        int ipt;
        cin >> ipt;
        lin.push_back(ipt);
    }

    sort(lin.begin(), lin.end());

    int MAX = 0;
    for (int i = 0; i < N; i++)
    {
        int num = lin[i] * (N - i);
        MAX = max(MAX, num);
    }

    cout << MAX << '\n';

    return 0;
}