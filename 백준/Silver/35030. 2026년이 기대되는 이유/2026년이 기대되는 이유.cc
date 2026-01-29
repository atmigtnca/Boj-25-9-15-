#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
vector<int> rstN, caseN;
bool sosu[100001];
int T, MAX_N = 0;

void resulT()
{
    for (auto mem : rstN)
    {
        cout << caseN[mem] << '\n';
    }
    return;
}

void sosU()
{
    sosu[0] = true;
    sosu[1] = true;
    for (int i = 2; i <= 100000; i++)
    {
        for (int j = 2; j * i < 100000; j++)
        {
            int num = j * i;
            sosu[num] = true;
        }
    }
}

bool finD(int num)
{
    if (sosu[num + 1])
    {
        return false;
    }

    string ipt = to_string(num);
    int sze = ipt.size();

    if (sze == 1)
    {
        return true;
    }

    string head, tail;
    for (int i = 1; i < sze; i++)
    {
        head = "", tail = "";
        for (int h = 0; h < i; h++)
        {
            head += ipt[h];
        }
        for (int t = i; t < sze; t++)
        {
            tail += ipt[t];
        }
        int mul = stoi(head) * stoi(tail);
        if (!sosu[mul + 1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void input()
{
    cin >> T;
    rstN.reserve(T);
    for (int i = 0; i < T; i++)
    {
        int ipt;
        cin >> ipt;
        rstN.push_back(ipt);
        if (ipt > MAX_N)
        {
            MAX_N = ipt;
        }
    }
    caseN.resize(MAX_N + 1);
    for (int i = 1; i <= MAX_N; i++)
    {
        bool chk = finD(i);

        if (chk)
        {
            caseN[i] = caseN[i - 1] + 1;
        }
        else
        {
            caseN[i] = caseN[i - 1];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    sosU();
    input();
    resulT();

    return 0;
}