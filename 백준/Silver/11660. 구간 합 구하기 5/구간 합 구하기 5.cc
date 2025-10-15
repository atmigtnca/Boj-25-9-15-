#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;
    vector<vector<int>> gad(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        int ad = 0;
        for (int j = 1; j <= n; ++j)
        {
            int a;
            cin >> a;
            ad += a;
            gad[i][j] = gad[i - 1][j] + ad;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        long long rst = gad[y2][x2] - gad[y1 - 1][x2] - gad[y2][x1 - 1] + gad[y1 - 1][x1 - 1];
        cout << rst << "\n";
    }

    return 0;
}