#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
vector<int> trg, frd;
int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    trg.resize(M + 1);
    frd.resize(N + 1);
    for (int i = 1; i <= M; i++)
    {
        cin >> trg[i];
    }

    for (int i = 1; i <= M; i++)
    {
        int num, X = 0;
        for (int j = 1; j <= N; j++)
        {
            cin >> num;
            if (trg[i] == num)
            {
                frd[j]++;
            }
            else
            {
                X++;
            }
        }
        frd[trg[i]] += X;
    }

    for (int i = 1; i <= N; i++)
    {
        cout << frd[i] << '\n';
    }

    return 0;
}