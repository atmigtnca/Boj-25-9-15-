#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
vector<queue<string>> prt;
int N;

string check()
{
    string cseteram, word;
    getline(cin, cseteram);

    for (int c = 0; c <= cseteram.size(); c++)
    {
        if (cseteram[c] == ' ' || c == cseteram.size())
        {
            bool fnd = true;
            for (int i = 0; i < N; i++)
            {
                if (prt[i].empty())
                {
                    continue;
                }
                string cmp = prt[i].front();
                if (cmp == word)
                {
                    fnd = false;
                    prt[i].pop();
                    break;
                }
            }
            if (fnd)
            {
                return "Impossible";
            }
            word = "";
            continue;
        }
        word += cseteram[c];
    }

    for (int i = 0; i < N; i++)
    {
        if (!prt[i].empty())
        {
            return "Impossible";
        }
    }

    return "Possible";
}

void input()
{
    cin >> N;
    cin.ignore();
    prt.resize(N);

    string tmp;
    for (int s = 0; s < N; s++)
    {
        getline(cin, tmp);
        string word = "";
        for (int c = 0; c <= tmp.size(); c++)
        {
            if (tmp[c] == ' ' || c == tmp.size())
            {
                prt[s].push(word);
                word = "";
                continue;
            }
            word += tmp[c];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    cout << check() << '\n';

    return 0;
}