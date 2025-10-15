#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> mat(n * m, 0);

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            cin >> mat[(m * i) + j];
        }
    }

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            int a;
            cin >> a;
            mat[(m * i) + j] += a;
        }
    }

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            cout << mat[(m * i) + j] << " ";
        }
        cout << '\n';
    }

    return 0;
}