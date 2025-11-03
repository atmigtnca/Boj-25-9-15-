#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> dwarfs(9);

    int all = 0;
    for (size_t i = 0; i < 9; i++)
    {
        cin >> dwarfs[i];
        all += dwarfs[i];
    }

    int first = 0, second = 0;
    bool fud = false;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = i + 1; j < 9; j++)
        {
            int alltest = all;
            alltest -= dwarfs[i] + dwarfs[j];
            if (alltest == 100)
            {
                first = j, second = i;
                fud = true;
                break;
            }
        }
        if (fud)
        {
            break;
        }
    }

    dwarfs.erase(dwarfs.begin() + first);
    dwarfs.erase(dwarfs.begin() + second);

    sort(dwarfs.begin(), dwarfs.end());

    for (auto& mem : dwarfs)
    {
        cout << mem << '\n';
    }

    return 0;
}