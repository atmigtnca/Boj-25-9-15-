#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int up = 0, down = 0;

    string card;
    cin >> card;

    for (size_t i = 0; i < card.size(); i++)
    {
        if (card[i] == '1')
        {
            up++;
        }
        else
        {
            down++;
        }
        char srt = card[i];
        while (i + 1 < card.size() && card[i + 1] == srt)
        {
            i++;
        }
    }

    cout << min(up, down) << '\n';

    return 0;
}